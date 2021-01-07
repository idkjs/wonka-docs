Js.log("
## fromList

`fromList` transforms a list into a source, emitting each item synchronously.

> _Note:_ This operator is only useful in Reason / OCaml where lists are a builtin
> data structure.

This is otherwise functionally the same as `fromArray`.

```reason
Wonka.fromList([1, 2, 3]);
```
*/
/** doesnt log anything. This just describes defining a source */
");
let source = Wonka.fromList([1, 2, 3]);
