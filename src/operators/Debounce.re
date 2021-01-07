let sourceA = Wonka.interval(10) |> Wonka.take(5);
let sourceB = Wonka.fromValue(1);
let start = () => {
  Js.log(__MODULE__);

  Js.log(
    "/* The five values from sourceA will be omitted */
/* After these values and after 20ms `1` will be logged */",
  );
  Wonka.concat([|sourceA, sourceB|])
  |> Wonka.debounce((. _x) => 20)
  |> Wonka.subscribe((. x) => print_int(x));
};
let _ = start();
