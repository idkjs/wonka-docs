Js.log("## throttle

`throttle` emits values of a source, but after each value it will omit all values for
the given amount of milliseconds. It enforces a time of silence after each value it
receives and skips values while the silence is still ongoing.

This is very similar to `debounce` but instead of waiting for leading time before a
value it waits for trailing time after a value.

> _Note:_ This operator is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
Wonka.interval(10)
  |> Wonka.throttle((. _x) => 50)
  |> Wonka.take(2)
  |> Wonka.subscribe((. x) => print_int(x));
/* Outputs 0 6 to the console. */
```")

Wonka.interval(10)
  |> Wonka.throttle((. _x) => 50)
  |> Wonka.take(2)
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
