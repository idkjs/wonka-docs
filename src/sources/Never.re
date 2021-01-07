Js.log("## never

This is source is similar to [`empty`](#empty).
It doesn't emit any values but also never completes.

```reason
Wonka.never
  |> Wonka.forEach((. value) => {
    /* This will never be called */
    ()
  });
```")

Wonka.never
  |> Wonka.forEach((. value) => {
    /* This will never be called */
    ()
  });
