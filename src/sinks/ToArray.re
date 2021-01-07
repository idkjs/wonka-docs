Js.log("
## toArray

`toArray` returns an array, which contains all values from a pull source.
This sink is primarily intended for synchronous pull streams. Passing it
an asynchronous push streams may result in an empty array being returned.

If you're passing an asynchronous push stream `toArray` will cancel it
before it returns an array.

> _Note:_ If you're using this sink, make sure that your input source streams
> the values you're collecting partly or fully synchronously.

```reason
Wonka.fromArray([|1, 2, 3|])
  |> Wonka.map((. x) => x * 2)
  |> Wonka.toArray
/* Returns [|2, 4, 6|] */")

let _ = Wonka.fromArray([|1, 2, 3|])
  |> Wonka.map((. x) => x * 2)
  |> Wonka.toArray
