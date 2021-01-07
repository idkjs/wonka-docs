Js.log(
  "## toPromise

`toPromise` returns a promise, which resolves on the last value of a source.

> _Note:_ This source is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
Wonka.fromArray([|1, 2, 3|])
  |> Wonka.toPromise
  |> Js.Promise.then_(x => {
    print_int(x);
    Js.Promise.resolve(())
  })
/* Prints 3 to the console. */",
);

Wonka.fromArray([|1, 2, 3|])
|> Wonka.toPromise
|> Js.Promise.then_(x => {
     print_int(x);
     Js.Promise.resolve();
   })
|> ignore;
