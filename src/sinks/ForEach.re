("## forEach

`forEach` works the same as `subscribe` but doesn't return a subscription.
It will just call the passed callback for each incoming value.

```reason
Wonka.fromArray([|1, 2, 3|])
  |> Wonka.forEach((. x) => print_int(x));
/* Returns unit; Prints 123 to the console. */")
->Js.log

Wonka.fromArray([|1, 2, 3|])
  |> Wonka.forEach((. x) => print_int(x));
