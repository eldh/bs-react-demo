type values = {
  value: string,
  label: string,
};

let renderOption = ({value, label}) =>
  <option value key=value> {R.s(label)} </option>;

let component = ReasonReact.component(__MODULE__);

let make = (~onChange, ~options, _children) => {
  ...component,
  render: _ =>
    <select
      className=Css.(
        style([
          marginBottom(px(20)),
          marginTop(px(20)),
          fontSize(px(18)),
        ])
      )
      onChange={
        e => {
          let value = (e |> ReactEvent.Form.currentTarget)##value;
          onChange(value);
        }
      }>
      {options->Belt_List.map(renderOption)->R.l}
    </select>,
};