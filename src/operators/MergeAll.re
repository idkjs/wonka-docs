Js.log("## mergeAll

`mergeAll` will merge all sources emitted on an outer source into a single one.
It's very similar to `merge`, but instead accepts a source of sources as an input.

> _Note:_ This operator is also exported as `flatten` which is just an alias for `mergeAll`
/* Prints 1 2 3 4 5 6 to the console. */")
// ```reason
let sourceA = Wonka.fromArray([|1, 2, 3|]);
let sourceB = Wonka.fromArray([|4, 5, 6|]);

Wonka.fromList([sourceA, sourceB])
  |> Wonka.mergeAll
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
