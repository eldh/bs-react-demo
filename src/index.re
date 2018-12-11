[@bs.module "./serviceWorker"]
external registerServiceWorker: unit => unit = "register";
[@bs.module "./serviceWorker"]
external unregisterServiceWorker: unit => unit = "unregister";

ReactDOMRe.renderToElementWithId(<App />, "root");

/* If you want your app to work offline and load faster, you can change
   unregisterServiceWorker() to registerServiceWorker() below. Note this comes with some pitfalls.
   Learn more about service workers: http://bit.ly/CRA-PWA */
unregisterServiceWorker();