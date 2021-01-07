Js.log("## fromPromise

`fromPromise` transforms a promise into a source, emitting the promisified value on
the source once it resolves.

> _Note:_ This source is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 1)); /* Just an example promise */
let _ = Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log(x));
/* Prints 1 to the console. */
```")

let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 1)); /* Just an example promise */
let _ = Wonka.fromPromise(promise) |> Wonka.subscribe((. x) => Js.log(x));
