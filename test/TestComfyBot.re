open ComfyBot;
open Js.Promise;
/* if getting token from process##env */
let token =
  "authtoken="
  ++ Js.Dict.get(Node.Process.process##env, "STRIMS_CLIENT_TOKEN")->Belt.Option.getExn;
let _ = Js.log2("token", token);
/* if getting token from bot-setting.json */
// let token = Js.Json.parseExn(Node.Fs.readFileSync("bot-settings.json", `utf8)) -> Js.Json.decodeObject -> Belt.Option.getExn -> Js.Dict.get("token") -> Belt.Option.getExn -> Js.Json.decodeString -> Belt.Option.getExn

bot({token: token})
|> then_(bot => {
     Js.log(bot);
     resolve();
   })
|> catch(error => {
     Js.log(error);
     resolve();
   });

let rec hang = () => Js.Global.setTimeout(hang, 50000) |> ignore;