("## scan

Accumulate emitted values of a source in a accumulator, similar to JavaScript `reduce`.

/* Prints 1 3 6 10 15 21 to the console. */")->Js.log
Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.scan((. acc, x) => acc + x, 0)
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
/* Prints 1 3 6 10 15 21 to the console. */
