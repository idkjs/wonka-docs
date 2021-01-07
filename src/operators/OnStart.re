
("## onStart

Run a callback when the `Start` signal is sent to the sink by the source.

/* Logs onStart to the console, pauses for one second to allow the timeout to finish,
then logs 'Resolve' to the console. */")->Js.log
let promise =
  Js.Promise.make((~resolve, ~reject as _) =>
    Js.Global.setTimeout(() => resolve(. "Resolve"), 1000) |> ignore
  );

Wonka.fromPromise(promise)
  |> Wonka.onStart((.) => print_endline("onStart"))
  |> Wonka.subscribe((. _val) => print_endline(_val))|> ignore;
/* Logs onStart to the console, pauses for one second to allow the timeout to finish,
then logs "Resolve" to the console. */
