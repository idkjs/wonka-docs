// Wonka.fromValue("test")
// |> Wonka.map((. x) => x ++ " this")
// |> Wonka.forEach((. x) => print_endline(x));
let line = "-------------------------------------------------";
let _ = {
  Js.log @@ {j|$line|j};

  Js.log @@ {j|Interval EXAMPLE|j};
  Wonka.interval(50)
  |> Wonka.buffer(Wonka.interval(100))
  |> Wonka.take(2)
  |> Wonka.subscribe((. buffer) => {
       Js.Array.forEach(num => print_int(num), buffer);
       print_endline(";");
     });
};
Js.log @@ {j|$line|j};

let sourceOne = Wonka.fromArray([|1, 2, 3|]);
let sourceTwo = Wonka.fromArray([|6, 5, 4|]);
Js.log @@ {j|Concat EXAMPLE|j};
let _ =
  Wonka.concat([|sourceOne, sourceTwo|])
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 1 2 3 6 5 4 to the console. */

Js.log @@ {j|$line|j};
let sourceOne = Wonka.fromArray([|1, 2, 3|]);
let sourceTwo = Wonka.fromArray([|4, 5, 6|]);
Js.log("Prints 56789 (1+4, 2+4, 3+4, 3+5, 3+6) to the console.")
let _ =
  Wonka.combine(sourceOne, sourceTwo)

  |> Wonka.subscribe((. (a, b)) => print_int(a + b));

/* Prints 56789 (1+4, 2+4, 3+4, 3+5, 3+6) to the console. */
