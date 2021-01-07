Js.log(
  "---
title: Sources
order: 0
---

A 'source' in Wonka is a provider of data. It provides data to a 'sink' when the 'sink' requests it. This is called a pull signal and for synchronous sources no time will pass between the sink pulling a new value and a source sending it. For asynchronous sources, the source may either ignore pull signals and just push values or send one some time after the pull signal.

## fromArray

`fromArray` transforms an array into a source, emitting each item synchronously.

```reason
Wonka.fromArray([|1, 2, 3|]);"
/** doesnt log anything. This just describes defining a source */
);
let source = Wonka.fromArray([|1, 2, 3|]);
