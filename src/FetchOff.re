module Create = (Config: {type t;}) => {
  open Js_promise;
  type response = {. [@bs.meth] "json": unit => Js_promise.t(Config.t)};
  [@bs.val]
  external __internal__fetch__: string => Js_promise.t(response) = "fetch";
  let fetch = url =>
    url
    |> __internal__fetch__
    |> then_(res => {
         /* Js.log2("res", res); */
         ();
         res##json();
       });

  type result =
    | NotSent
    | Loading
    | Error
    | Ok(Config.t);
  let hook = url => {
    let (value, setValue) = ReactHooks.useState(NotSent);
    ReactHooks.useEffect(
      () => {
        setValue(. Loading);
        let _ =
          fetch(url)
          |> then_(res => {
               setValue(. Ok(res));
               resolve();
             });
        None;
      },
      [|url|],
    );
    value;
  };
};