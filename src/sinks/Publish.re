Js.log("## publish

`publish` subscribes to a source, like `subscribe` does, but doesn't accept
a callback function. It's useful for side-effects, where the values are already being
used as part of the stream itself.

In this example we're using [`onPush`](./operators.md#onpush) to pass a callback to react to incoming
values instead.

```reason
Wonka.fromArray([|1, 2, 3|])
  |> Wonka.onPush((. x) => print_int(x))
  |> Wonka.publish;
/* Prints 123 to the console. */")

let _ = Wonka.fromArray([|1, 2, 3|])
  |> Wonka.onPush((. x) => print_int(x))
  |> Wonka.publish;
