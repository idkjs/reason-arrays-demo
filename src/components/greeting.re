let component = ReasonReact.statelessComponent("Greeting");

let text = ReasonReact.stringToElement;

/* underscores before names indicate unused variables. We name them for clarity */
let make = (~name, _children) => {...component, render: (self) => <button> (text(name)) </button>};