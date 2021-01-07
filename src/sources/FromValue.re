Js.log(
  "
## fromValue

`fromValue` takes a single value and creates a source that emits the value and
completes immediately afterwards.

```reason
Wonka.fromValue('a value');
```",
);

let source = Wonka.fromValue("a value");
Js.log(source)
let _ = Wonka.fromValue("a value")|>(v=>Js.log(v));
