Js.log(
  __MODULE__
);
Js.log(
  "/* waits 10ms then prints 1, waits 10ms then prints 2, waits 10ms then ends */",
);

let _=Wonka.fromList([1, 2])
  |> Wonka.delay(10)
  |> Wonka.subscribe((. x) => print_int(x));

Js.log("/* The five values from sourceA will be omitted */
/* After these values and after 20ms `1` will be logged */")
let sourceA = Wonka.interval(10)
  |> Wonka.take(5);
let sourceB = Wonka.fromValue(1);

Wonka.concat([|sourceA, sourceB|])
  |> Wonka.debounce((. _x) => 20)
  |> Wonka.subscribe((. x) => print_int(x))
  |>ignore;
