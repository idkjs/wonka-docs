Js.log("## toCallbag

`toCallbag` returns a [spec-compliant JS Callbag](https://github.com/callbag/callbag), which emits the same signals
as a Wonka source.

Since Wonka's sources are very similar to callbags and only diverge from the specification
minimally, Callbags map to Wonka's sources very closely and `toCallbag` only creates a thin
wrapper which is mostly concerned with converting between the type signatures.

> _Note:_ This sink is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
/* This example uses the callbag-iterate package for illustrative purposes */
[@bs.module] external callbagIterate:
  (. ('a => unit)) => (. Wonka.callbagT('a)) => unit = `callbag-iterate`;

let callbag = Wonka.fromArray([|1, 2, 3|])
  |> Wonka.toCallbag;

callbagIterate(. value => {
  print_int(value);
})(. callbag); /* Prints 1 2 3 to the console. */")
// open Wonka_types;
// type callbagT('a) = (callbagSignal, callbagData('a)) => unit;
// open Wonka;
module Callbag = Wonka_callbag
[@bs.module] external callbagIterate:
  (. ('a => unit)) => (. Callbag.callbagT('a) ) => unit = "callbag-iterate";
// [@bs.module] external callbagIterate:
//   (. ('a => unit)) => (. Wonka_callbag.callbagT('a) ) => unit = "callbag-iterate";

let callbag = Wonka.fromArray([|1, 2, 3|])
  |> Wonka.toCallbag;

//   33 │ callbagIterate(. value => {
//   34 │   print_int(value);
//   35 │ })(. callbag);
//   Unused attribute: bs
// This means such annotation is not annotated properly.
// for example, some annotations is only meaningful in externals
// probably need a better error here. Seems the appropriate error should be
// `  Toplevel expression is expected to have unit type.`
let _ = callbagIterate(. value => {
  print_int(value);
})(. callbag);
