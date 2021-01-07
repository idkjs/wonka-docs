Js.log("## interval

`interval` creates a source that emits values after the given amount of milliseconds.
Internally it uses `setInterval` to accomplish this.

> _Note:_ This source is only available in JavaScript environments, and will be excluded
> when compiling natively.

```reason
Wonka.interval(50)
  |> Wonka.subscribe((. x) => Js.log(x));
/* Prints 0 1 2... to the console. */
/* The incrementing number is logged every 50ms */
```")

ignore(Wonka.interval(50)
  |> Wonka.subscribe((. x) => Js.log(x)));
