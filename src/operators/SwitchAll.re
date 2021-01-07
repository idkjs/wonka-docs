("## switchAll

`switchAll` will combined sources emitted on an outer source together, subscribing
to only one source at a time, and cancelling the previous inner source, when it hasn't
ended while the next inner source is created.

It's very similar to `switchMap`, but instead accepts a source of sources.

```reason
Wonka.interval(50)
  |> Wonka.map((. _value) =>
    Wonka.interval(40))
  |> Wonka.switchAll
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 1 2 3 to the console. */
```")->Js.log

Wonka.interval(50)
  |> Wonka.map((. _value) =>
    Wonka.interval(40))
  |> Wonka.switchAll
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
