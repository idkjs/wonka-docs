// ModuleName.log()
Js.log(
  __MODULE__
);
Js.log(
  "/* After 1s, 1 will be emitted. After an additional 2s, 2 will be emitted.
After an additional 3s, 3 will be emitted. After an additional 4s, 4 will be emitted.
After an additional 5s, 5 will be emitted. After an additional 6s, 6 will be emitted. */",
);

let source = Wonka.fromArray([|1, 2, 3, 4, 5, 6|]);

let _ =
  source
  |> Wonka.concatMap((. _val) =>
       Wonka.delay(_val * 1000, Wonka.fromValue(_val))
     )
  |> Wonka.subscribe((. _val) => print_int(_val));

/* After 1s, 1 will be emitted. After an additional 2s, 2 will be emitted.
   After an additional 3s, 3 will be emitted. After an additional 4s, 4 will be emitted.
   After an additional 5s, 5 will be emitted. After an additional 6s, 6 will be emitted. */
