("## mergeMap

`mergeMap` allows you to map values of an outer source to an inner source.
This allows you to create nested sources for each emitted value, which will
all be merged into a single source, like with `mergeAll`.

Unlike `concatMap` all inner sources will be subscribed to at the same time
and all their values will be emitted on the output source as they come in.
/* Prints 0 1 1 2 to the console. */")
->Js.log;

// ```reason
Wonka.fromList([1, 2])
|> Wonka.mergeMap((. value) => Wonka.fromList([value - 1, value]))
|> Wonka.subscribe((. x) => print_int(x))
|> ignore;
/* Prints 0 1 1 2 to the console. */
