("## skipWhile

Skip values emitted from the source while they return `true` for the provided predicate function.

```reason
let source = Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);

source
|> Wonka.skipWhile((. _val) => _val < 5)
|> Wonka.subscribe((. _val) => print_int(_val));

/* Prints 5 6 to the console, as 1 2 3 4 all return true for the predicate function. */")
->Js.log


let source = Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);

source
|> Wonka.skipWhile((. _val) => _val < 5)
|> Wonka.subscribe((. _val) => print_int(_val))|>ignore;
