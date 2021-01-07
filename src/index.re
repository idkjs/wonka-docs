// let port = 3000
// Js.log @@ {j|Listening at port $port|j}
include Sources

// Wonka.fromValue("test")
//   |> Wonka.map((.x) => x ++ " this")
//   |> Wonka.forEach((.x) => print_endline(x));


include GettingStarted
include ConcatAll
include ConcatMap
include Debounce
include Delay
// ## combine

// `combine` two sources together to a single source. The emitted value will be a combination of the two sources, with all values from the first source being emitted with the first value of the second source _before_ values of the second source are emitted.

// ```reason
// >>>> Start compiling
// bsb: [1/1] src/index.cmj
// FAILED: src/index.cmj

//   We've found a bug for you!
//   /Users/mandalarian/Downloads/resume-api/src/index.re:23:6-14

//   21 │
//   22 │ Wonka.combine(sourceOne)
//   23 │   |> sourceTwo
//   24 │   |> Wonka.subscribe((. (a, b)) => print_int(a + b));

//   This has type:
//     Wonka_types.sourceT(int) (defined as Wonka_types.sinkT(int) => unit)
//   Somewhere wanted:
//     (Wonka_types.sourceT('a) => Wonka_types.sourceT((int, 'a))) => 'b

//   The incompatible parts:
//     Wonka_types.sinkT(int) (defined as (. Wonka_types.signalT(int)) => unit)
//     vs Wonka_types.sourceT('a) => Wonka_types.sourceT((int, 'a))
// let sourceOne = Wonka.fromArray([|1, 2, 3|]);
// let sourceTwo = Wonka.fromArray([|4, 5, 6|]);

// Wonka.combine(sourceOne)
//   |> sourceTwo
//   |> Wonka.subscribe((. (a, b)) => print_int(a + b));

