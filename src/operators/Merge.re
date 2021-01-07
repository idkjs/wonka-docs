Js.log(
  "## merge

`merge` merges an array of sources together into a single source. It subscribes
to all sources that it's passed and emits all their values on the output source.
",
);

let sourceA = Wonka.fromArray([|1, 2, 3|]);
let sourceB = Wonka.fromArray([|4, 5, 6|]);

Wonka.merge([|sourceA, sourceB|])
|> Wonka.subscribe((. x) => print_int(x))
|> ignore;
/* Prints 1 2 3 4 5 6 to the console. */
