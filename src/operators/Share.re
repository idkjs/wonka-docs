"## share

`share` ensures that all subscriptions to the underlying source are shared.

By default Wonka's sources are lazy. They only instantiate themselves and begin
emitting signals when they're being subscribed to, since they're also immutable.
This means that when a source is used in multiple places, their underlying subscription
is not shared. Instead, the entire chain of sources and operators will be instantiated
separately every time.

The `share` operator prevents this by creating an output source that will reuse a single
subscription to the parent source, which will be unsubscribed from when no sinks are
listening to it anymore.

This is especially useful if you introduce side-effects to your sources,
for instance with `onStart`.

/* Without share this would print 'start' twice: */"
->Js.log;

/**
see https://github.com/kitten/wonka/issues/104#issuecomment-756190222
This has no type that can be used to fill out the missing type of the source, hence it'll need to be recast or used in a way that gives the stream a type
 */
let start = "/**
see https://github.com/kitten/wonka/issues/104#issuecomment-756190222
This has no type that can be used to fill out the missing type of the source, hence it'll need to be recast or used in a way that gives the stream a type. Using Obj.magic here to cast the type and see the function in action.
 */"
let source =
  Wonka.never
  |> Wonka.onStart((.) => print_endline(start))
  |> Wonka.share
  |> Obj.magic;

Wonka.publish(source) |> ignore;
Wonka.publish(source) |> ignore;

