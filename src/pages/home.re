[@bs.module] external gql : ReasonApolloTypes.gql = "graphql-tag";

/* Describe the result type */
type episode = {. "id": string, "title": string, "episode": string};

type data = {. "allEpisodes": list(episode)};

/* type data = {. "allEpisodes": array(allEpisodes)}; */
/* Write graphql query */
let query =
  [@bs]
  gql({|
  query allEpisodes {
    allEpisodes{
      id
      title
      episode
    }
  }
|});

/* Pass the above information to the Apollo Client */
module Config = {
  type responseType = data;
  let query = query;
};

/* You can now use it as a JSX call */
module FetchEpisodes = Apollo.Client(Config);

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_) => {
  ...component,
  render: (_self) =>
    <View>
      <Hello message="Hello from home component" />
      /* <Greeting name="Tony" /> */
      <FetchEpisodes>
        (
          (response) => {
            let episodeItems =
              response##data##allEpisodes
              |> Array.map((episode) => <Episode key=episode##id episode=episode##title />);
            <div> <h1> (ReasonReact.stringToElement("Episodes!")) </h1> </div>(
              ReasonReact.arrayToElement(episodeItems)
            )
          }
        )
      </FetchEpisodes>
    </View>
};