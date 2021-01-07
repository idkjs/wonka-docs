"## sample

`sample` emits the previously emitted value from an outer source every time
an inner source (notifier) emits.

In combination with `interval` it can be used to get values from a noisy source
more regularly.

/* Prints 10 20 to the console. */"
->Js.log;
// Wonka.interval(5)
let _ =
  Wonka.interval(10)
  |> Wonka.sample(Wonka.interval(100))
  |> Wonka.take(2)
  |> Wonka.subscribe((. x) => print_int(x));
