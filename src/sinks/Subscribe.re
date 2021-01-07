Js.log("---
title: Sinks
order: 2
---

A sink in Wonka expects to be delivered data. A `sink` communicates with a source via the 'talkback' function provided by the source. Wonka has the following `sink` operators.

## subscribe

`subscribe` accepts a callback function to execute when data is received from the source, in addition to the source itself.

```reason
Wonka.fromArray([|1, 2, 3|])
  |> Wonka.subscribe((. x) => print_int(x));
/* Prints 123 to the console. */")

Wonka.fromArray([|1, 2, 3|])
  |> Wonka.subscribe((. x) => print_int(x))|>ignore;
