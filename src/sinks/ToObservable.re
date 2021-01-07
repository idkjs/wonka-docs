Js.log(
  "## toObservable
### This example uses ocaml classes which are not supported in rescript.

`toObservable` returns a [spec-compliant JS Observable](https://github.com/tc39/proposal-observable), which emits the same
values as a source.

As per the specification, the Observable is annotated using `Symbol.observable`.

> _Note:_ This sink is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
let observable = Wonka.fromArray([|1, 2, 3|])
  |> Wonka.toObservable;

observable##subscribe([@bs] {
  as _;
  pub next = value => print_int(value);
  pub complete = () => ();
  pub error = _ => ();
}); /* Prints 1 2 3 to the console. */",
);

let observable = Wonka.fromArray([|1, 2, 3|]) |> Wonka.toObservable;

let _ =
  observable##subscribe(
    [@bs]
    {
      as _;
      pub next = value => print_int(value);
      pub complete = () => ();
      pub error = _ => ()
    },
  );
