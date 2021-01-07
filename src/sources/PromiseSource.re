Js.log(
  "

## make

`make` can be used to create an arbitrary source. It allows you to make a source
from any other data.
It accepts a function that receives an `observer` and should return a teardown
function. It's very similar to creating an [Observable in `zen-observable`](https://github.com/zenparsing/zen-observable#new-observablesubscribe).

The function you pass to `make` is called lazily when a sink subscribes to the
source you're creating. The first argument `observer` is a tuple with two methods:

- `next(value)` emits a value on the sink
- `complete()` ends the source and completes the sink

The subscriber function also needs to return a `teardown` function. This function
is called when either `complete()` is called and the source ends, or if the source
is being cancelled, since the sink unsubscribed.

In this example we create a source that waits for a promise to resolve and emits
values from the array of that promise.

```reason
let waitForArray = () => Js.Promise.resolve([|1, 2, 3|]);

let source = Wonka.make((. observer) => {
  let (next, complete) = observer;
  let cancelled = ref(false);
  let promise = waitForArray();

  Js.Promise.then_(arr => {
    if (!cancelled^) {
      Array.iter(next, arr);
      complete();
    }
  }, promise);

  () => cancelled := true;
});
```
",
);

module PromiseHelper = {
  external promiseErrorToJsExn: Js.Promise.error => Js.Exn.t = "%identity";

  /**
 * converts a promise to a Wonka *result* source.
 * Upon promise resolution / rejection, the source
 * will push *next* & *complete* events
 */
  let fromPromise = (promise: Js.Promise.t('a)) => {
    Wonka.make(
      (. observer: Wonka.Types.observerT(Belt.Result.t('a, Js.Exn.t))) => {
      let cancelled = ref(false);
      let _ =
        promise
        |> Js.Promise.then_(value =>
             Belt.Result.Ok(value) |> Js.Promise.resolve
           )
        |> Js.Promise.catch(error =>
             promiseErrorToJsExn(error)
             |> (error => Belt.Result.Error(error))
             |> Js.Promise.resolve
           )
        |> Js.Promise.then_(value => {
             if (! cancelled^) {
               observer.next(value);
               observer.complete();
             };
             Js.Promise.resolve();
           });
      (.) => cancelled := true;
    });
  };
};
open Wonka_types;
let waitForArray = () => Js.Promise.resolve([|1, 2, 3|]);
Js.log(PromiseHelper.fromPromise(waitForArray()));
let promise =
  Js.Promise.make((~resolve, ~reject as _) => resolve(. waitForArray())); /* Just an example promise */
let _ = Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log(x));
let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 1)); /* Just an example promise */
let _ = Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log(x));
let source =
  Wonka.make((. observer) => {
    let next = observer.next;
    let complete = observer.complete;

    let cancelled = ref(false);
    let promise = waitForArray();
    let _ =
      Js.Promise.then_(
        arr =>
          ! cancelled^
            ? {
              Array.iter(next, arr);
              complete() |> Js.Promise.resolve;
            }
            : Js.Promise.resolve(),
        promise,
      );

    (.) => cancelled := true;
  });
let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. source));
let _ =
  Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log2("x", x));
let _ =
  promise
  |> Wonka.fromPromise
  |> Wonka.map((. value) => Ok(Js.log2(" Wonka.map((. value)", value)));
let _ =
source
  |> Wonka.take(1)
  |> Wonka.map((. value) => Ok(Js.log2(" Wonka.take(1)", value)));
// let _ =
//   Wonka.make((. observer) => {
//     let next = observer.next;
//     let complete = observer.complete;

//     let cancelled = ref(false);
//     let promise = waitForArray();
//     let _ =Js.Promise.then_(
//       arr => {
//         Js.Promise.resolve(
//           if (! cancelled^) {
//             Array.iter(next, arr);
//             complete();
//           },
//         )
//       },
//       promise,
//     );

//     (.) => cancelled := true;
//   });
let _ =
  Wonka.make((. observer) => {
    let next = observer.next;
    let complete = observer.complete;

    let cancelled = ref(false);
    let promise = waitForArray();
    let x =
      Js.Promise.then_(
        arr => {
          //   Js.log2("arr",arr)|>ignore
          Js.Promise.resolve(
            if (! cancelled^) {
              Array.iter(next, arr);
              // Js.log(next());
              complete();
            },
          )
        },
        promise,
      );
    Js.log2("x", x) |> Js.Promise.resolve |> ignore;
    (.) => cancelled := true;
  });
