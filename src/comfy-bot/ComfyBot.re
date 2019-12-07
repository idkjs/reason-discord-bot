[%bs.raw {| require('isomorphic-fetch') |}];
[%%debugger.chrome];
open Ws;

type botSettings = {token: string};
type t = {
  settings: botSettings,
  ws: WebSocket.t,
};
exception SocketClosed(int, string);
exception SocketError(Dom.errorEvent);
Dotenv.config();
Random.self_init();

type chatMessage = {
  data: string,
  features: list(string),
  nick: string,
  timestamp: int,
};

let getRandomRedditPost = () =>
  Reddit.fetchRedditPosts()
  |> Js.Promise.then_(posts =>
       List.nth(posts, Random.int(List.length(posts))) |> Js.Promise.resolve
     );

let onChatMessage = (ws: WebSocket.t, message: chatMessage) =>
  if (Js.String.startsWith("!comfy", message.data)) {
    getRandomRedditPost()
    |> Js.Promise.then_((post: Reddit.redditPost) => {
         WebSocket.send(ws, post.data.url);
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(error => error |> Js.log |> Js.Promise.resolve)
    |> ignore;
  };

module Decode = {
  let chatMessage = json =>
    Json.Decode.{
      data: json |> field("data", string),
      features: json |> field("features", list(string)),
      nick: json |> field("nick", string),
      timestamp: json |> field("timestamp", int),
    };
};

let parseChatMessage = (str: string) =>
  str |> Json.parseOrRaise |> Decode.chatMessage;
type headers = {
  [@bs.as "Cookie"]
  cookie: string,
};
let _ =
  Js.log(
    Js.Dict.unsafeGet(Node.Process.process##env, "STRIMS_CLIENT_TOKEN"),
  );
// let token =
//   "authtoken="
//   ++ Js.Dict.unsafeGet(Node.Process.process##env, "STRIMS_CLIENT_TOKEN");
// let _ = Js.log2("token", token);
// let dict = Js.Dict.empty();
// Js.Dict.set(dict, "Cookie", Js.Json.string(token));
// let headers = Js.Json.stringify(Js.Json.object_(dict));
// let _ = Js.log2("headers",headers);
let bot = settings =>
  Js.Promise.make((~resolve, ~reject) => {
    let dict = Js.Dict.empty();
    Js.Dict.set(dict, "Cookie", Js.Json.string(settings.token));
    let headers = Js.Json.stringify(Js.Json.object_(dict));
    let _ = Js.log2("headers", headers);
    let ws =
      WebSocket.makeWithProtocols("wss://chat.strims.gg/ws", [|headers|]);
    ();
    WebSocket.(
      ws
      ->(
          on(
            `open_(
              () => {
                Js.log("opened PepoComfy");
                resolve(. {settings, ws});
              },
            ),
          )
        )
      ->(
          on(
            `message(
              data =>
                if (String.sub(data, 0, 3) == "MSG") {
                  onChatMessage(
                    ws,
                    parseChatMessage(
                      String.sub(data, 4, String.length(data) - 4),
                    ),
                  );
                },
            ),
          )
        )
      ->(
          on(
            `close(
              (code, reason) => {
                Js.log("Closed: " ++ string_of_int(code) ++ " " ++ reason);
                reject(. SocketClosed(code, reason));
              },
            ),
          )
        )
      // ->(
      //     on(
      //       `close(
      //         (code, reason) =>
      //           Js.log("closed: " ++ string_of_int(code) ++ reason);
      //           reject(. SocketClosed(code, reason))
      //       ),
      //     )
      //   )
      /*         Js.log("Opened");
                 resolve(. {settings, ws}); */
      // ->(on(`open_(() => Js.log("opened PepoComfy"))))
      ->(
          on(
            `error(error => Js.log("error: " ++ ErrorEvent.message(error))),
          )
        )
      ->ignore
    );
  }) /* ]*/ /*   }*/ /* |*/;
// let ws: WebSocket.t = [%bs.raw
//   {|
//   new require('isomorphic-ws')('wss://chat.strims.gg/ws', {
//     headers: { Cookie: `authtoken=${process.env.STRIMS_CLIENT_TOKEN}` }