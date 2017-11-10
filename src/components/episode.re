let component = ReasonReact.statelessComponent("Episode");

let make = (~style=?, ~episode, _children) => {
  ...component,
  render: (_self) => <View ?style> <h1> (ReasonReact.stringToElement(episode)) </h1> </View>
};