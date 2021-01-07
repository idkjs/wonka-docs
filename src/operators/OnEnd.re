("## onEnd

Run a callback when the `End` signal has been sent to the sink by the source, whether by way of the talkback passing the `End` signal or the source being exhausted of values.

/* Logs ResolveOne after one second, then ResolveTwo after an additional second, then onEnd immediately. */
")->Js.log
let promiseOne =
  Js.Promise.make((~resolve, ~reject as _) =>
    Js.Global.setTimeout(() => resolve(. "ResolveOne"), 1000) |> ignore
  );

let promiseTwo =
  Js.Promise.make((~resolve, ~reject as _) =>
    Js.Global.setTimeout(() => resolve(. "ResolveTwo"), 2000) |> ignore
  );

let sourceOne = Wonka.fromPromise(promiseOne);
let sourceTwo = Wonka.fromPromise(promiseTwo);

Wonka.concat([|sourceOne, sourceTwo|])
  |> Wonka.onEnd((.) => print_endline("onEnd"))
  |> Wonka.subscribe((. x) => print_endline(x))|>ignore;

/* Logs ResolveOne after one second, then ResolveTwo after an additional second, then onEnd immediately. */
