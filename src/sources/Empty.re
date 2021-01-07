Js.log("## empty

This is a source that doesn't emit any values when subscribed to and
immediately completes.

```reason
Wonka.empty
  |> Wonka.forEach((. value) => {
    /* This will never be called */
    ()
  });
```")
Wonka.empty
  |> Wonka.forEach((. value) => {
    /* This will never be called */
    ()
  });
