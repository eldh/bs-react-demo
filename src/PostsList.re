let liStyle = Css.(style([paddingBottom(px(10))]));
let component = ReasonReact.statelessComponent(__MODULE__);
let make = (~posts, _children) => {
  ...component,
  render: _ =>
    <ul className=Css.(style([listStyleType(`none), paddingLeft(px(0)), marginTop(px(0))]))>
      {
        posts
        ->Belt_Array.map(Reddit.dataGet)
        ->Belt_Array.map(data =>
            <li key={data->Reddit.idGet} className=liStyle>
              {data->Reddit.titleGet->R.s}
            </li>
          )
        ->R.a
      }
    </ul>,
};