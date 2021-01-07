"## takeLast

`takeLast` will take only the last n emissions from the source.

```reason
Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);
  |> Wonka.takeLast(3)
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 4 5 6 to the console. */"
->Js.log;

Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
|> Wonka.takeLast(3)
|> Wonka.subscribe((. x) => print_int(x))
|> ignore;
