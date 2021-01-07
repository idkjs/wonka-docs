// ## map

// `map` will transform values from a source by passing them through an iteratee that returns a new value.

// ```reason
Js.log("/* Prints 1 4 9 16 25 36 to the console. */")
let square = (. n) => n * n;

Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.map(square)
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
/* Prints 1 4 9 16 25 36 to the console. */
