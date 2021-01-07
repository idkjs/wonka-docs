Js.log(_ => Wonka.fromArray([|1, 2, 3|]));

let waitForArray = () => Js.Promise.resolve([|1, 2, 3|]);
// let source = Wonka.make((. observer) => {
//   let ( next, complete) = observer;
// //   let cancelled = ref(false);
// //   let promise = waitForArray();
// //   Js.Promise.then_(arr => {
// //     if (!cancelled^) {
// //       Array.iter(next, arr);
// //       complete();
// //     }
// //   }, promise);
// //   () => cancelled := true;
// });
let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 1)); /* Just an example promise */
let _ = Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log(x));
