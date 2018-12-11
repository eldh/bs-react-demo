Css.(
  global(
    "body",
    [
      backgroundColor(rgb(20, 20, 20)),
      fontFamily("Monaco"),
      margin(px(0)),
      padding(px(0)),
    ],
  )
);
Css.(
  global(
    "div, form, section, article, aside",
    [
      boxSizing(`borderBox),
      display(`flex),
      position(`relative),
      fontFamily("Monaco"),
      fontSize(px(18)),
      flexDirection(`column),
    ],
  )
);

let component = ReasonReact.statelessComponent(__MODULE__);

let make = children => {
  ...component,
  render: _ =>
    <div
      className=Css.(
        style([
          minHeight(vh(100.)),
          backgroundColor(rgb(0, 0, 0)),
          padding(px(10)),
          margin(px(0)),
          color(rgb(255, 255, 255)),
        ])
      )>
      ...children
    </div>,
};