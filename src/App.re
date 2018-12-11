let component = ReasonReact.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  render: _ => {
    ();
    <AppWrapper> "This is boring"->R.s </AppWrapper>;
  },
};