module Fetcher =
  Fetch.Create({
    type t = Reddit.jsonResult;
  });

let component = ReasonReact.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  render: _ => {
    let (subreddit, setSubreddit) = ReactHooks.useState("reasonml");
    let data = Fetcher.useFetch(subreddit->Reddit.getUrl);
    <AppWrapper>
      <Select options=Reddit.options onChange={v => setSubreddit(. v)} />
      {
        switch (data) {
        | NoResult => "Loading..."->R.s
        | BadResult => "Error"->R.s
        | GoodResult(v) => <PostsList posts={v->Reddit.getPosts} />
        }
      }
    </AppWrapper>;
  },
};