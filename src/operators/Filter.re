// ## filter

// `filter` will remove values from a source by passing them through an iteratee that returns a `bool`.

// ```reason
let isEven = (. n) => n mod 2 === 0;

let _=Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.filter(isEven)
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 246 to the console. */
