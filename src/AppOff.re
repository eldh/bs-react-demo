module Fetch =
  FetchOff.Create({
    type t = Reddit.jsonResult;
  });

let component = ReasonReact.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  render: _ => {
    let initial =
      switch (Belt_List.head(Reddit.options)) {
      | None => ""
      | Some(v) => v.value
      };
    let (selected, setSelected) = ReactHooks.useState(initial);
    let postsResult = Fetch.hook(Reddit.getUrl(selected));
    <AppWrapper>
      <Select onChange={value => setSelected(. value)} options=Reddit.options />
      {
        switch (postsResult) {
        | NotSent
        | Loading => "Loading..."->R.s
        | Error => "Error..."->R.s
        | Ok(v) => <PostsList posts={Reddit.getPosts(v)} />
        }
      }
    </AppWrapper>;
  },
};