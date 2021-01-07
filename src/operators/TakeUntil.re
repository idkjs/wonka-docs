("## takeUntil

Take emissions from an outer source until an inner source (notifier) emits.

```reason
let source = Wonka.interval(100);
let notifier = Wonka.interval(500);

source
  |> Wonka.takeUntil(notifier)
  |> Wonka.subscribe((. x) => print_int(x));

/* Pauses 100ms, prints 0, pauses 100ms, prints 1, pauses 100ms, prints 2, pauses 100ms,
prints 3, pauses 100, then completes (notifier emits). */")
->Js.log

let source = Wonka.interval(100);
let notifier = Wonka.interval(500);

let _ = source
  |> Wonka.takeUntil(notifier)
  |> Wonka.subscribe((. x) => print_int(x));
