Js.log("
`subscribe` also returns a 'subscription' type, which can be used to
unsubscribe from the source. This allows you to cancel a source and stop receiving
new incoming values.

```reason
let subscription = source
  |> Wonka.subscribe((. x) => print_int(x));

subscription.unsubscribe();")
let source = Wonka.fromArray([|1, 2, 3|]);
let subscription = source
  |> Wonka.subscribe((. x) => print_int(x));

subscription.unsubscribe();
