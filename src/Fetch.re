module Create = (Config: {type t;}) => {
  open Js_promise;

  type response = {. [@bs.meth] "json": unit => Js_promise.t(Config.t)};

  [@bs.val]
  external __fetch__: string => Js_promise.t(response) = "fetch";

  let fetch = url => url |> __fetch__ |> then_(res => res##json());

  type result = | GoodResult(Config.t) | BadResult | NoResult;

  let useFetch = url => {
    let (value, setValue) = ReactHooks.useState(NoResult);
    ReactHooks.useEffect(() => {
      setValue(. NoResult);
      fetch(url) |> then_(res => {
        setValue(. GoodResult(res));
        resolve()
      })
      |> catch(_ => {
        setValue(. BadResult)
        resolve()
      })
      None
    }, [|url|])
    value
  }

};