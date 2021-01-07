Js.log @@ {j|ConcatAll EXAMPLE|j};
let sourceOne = Wonka.fromArray([|1, 2, 3|]);
let sourceTwo = Wonka.fromArray([|6, 5, 4|]);
Js.log("/* Prints 1 2 3 6 5 4 to the console. */");
let _ =
  Wonka.fromList([sourceOne, sourceTwo])
  |> Wonka.concatAll
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 1 2 3 6 5 4 to the console. */
