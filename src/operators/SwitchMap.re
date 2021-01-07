"## switchMap

`switchMap` allows you to map values of an outer source to an inner source.
The inner source's values will be emitted on the returned output source. If
a new inner source is returned, because the outer source emitted a new value
before the previous inner source completed, the inner source is closed and unsubscribed
from.

This is similar to `concatMap` but instead of waiting for the last inner source to complete
before emitting values from the next, `switchMap` just cancels the previous inner source.

```reason
Wonka.interval(50)
  |> Wonka.switchMap((. _value) =>
    Wonka.interval(40))
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 1 2 3 to the console. */
/* The inner interval is cancelled after its first value every time */"
->Js.log;

let _ =
  Wonka.interval(50)
  |> Wonka.switchMap((. _value) => Wonka.interval(40))
  |> Wonka.take(3)
  |> Wonka.subscribe((. x) => print_int(x));
