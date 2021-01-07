Js.log("## takeWhile

Take emissions from the stream while they return `true` for the provided predicate function. If the first emission does not return `true`, no values will be `Push`ed to the sink.

```reason
let source = Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);

source
  |> Wonka.takeWhile((. x) => x < 5)
  |> Wonka.subscribe((. x) => print_int(x));

/* Prints 1 2 3 4 to the console. */")

let source = Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);

let _ =source
  |> Wonka.takeWhile((. x) => x < 5)
  |> Wonka.subscribe((. x) => print_int(x));
