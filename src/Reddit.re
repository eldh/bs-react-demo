
[@bs.deriving abstract]
type data = {
  title: string,
  id: string,
  url: string,
};

[@bs.deriving abstract]
type child = {
  data,
  kind: string,
};

[@bs.deriving abstract]
type dataList = {children: array(child)};

[@bs.deriving abstract]
type jsonResult = {
  [@bs.as "data"]
  dataList,
};

[@bs.scope "JSON"] [@bs.val]
external parseIntoMyData: string => jsonResult = "parse";

let getPosts = jsonData => jsonData->dataListGet->childrenGet;

let getUrl = subreddit => "https://www.reddit.com/r/" ++ subreddit ++ ".json";

let options: list(Select.values) = [
  {value: "reasonml", label: "ReasonML"},
  {value: "reactjs", label: "React"},
  {value: "vuejs", label: "Vue"},
  {value: "angularjs", label: "Angular"},
  {value: "emberjs", label: "Ember"},
];