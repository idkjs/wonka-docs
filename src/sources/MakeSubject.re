Js.log("## makeSubject

`makeSubject` can be used to create a subject. This is similar to [`make`](#make) without
having to define a source function. Instead a subject is a tuple of a source and
the observer's `next` and `complete` functions combined.

A subject can be very useful as a full event emitter. It allows you to pass a source
around but also have access to the observer functions to emit events away from
the source itself.

```reason
let subject = Wonka.makeSubject();
let { source, next, complete } = subject;

/* This will push the values synchronously to any subscribers of source */
next(1);
next(2);
next(complete);
```")
// let source = Wonka.fromList([1, 2, 3]);
// let source = Wonka.fromValue("a value");
// let subject = Wonka.makeSubject();
// let { source, next, complete } = subject;

// /* This will push the values synchronously to any subscribers of source */
// next(1);
// next(2);
// next(complete);
