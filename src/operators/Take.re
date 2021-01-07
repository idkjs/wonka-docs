"## take

`take` only a specified number of emissions from the source before completing. `take` is the opposite of `skip`.

```reason
Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 1 2 3 to the console. */"
->Js.log;

let _ =
  Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x));
