("## skip

`skip` the specified number of emissions from the source.

/* Prints 3 4 5 6 to the console, since the first two emissions from the source were skipped.*/")->Js.log

Wonka.fromArray([|1, 2, 3, 4, 5, 6|])
  |> Wonka.skip(2)
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
