// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Process = require("process");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var ComfyBot$Record = require("../src/comfy-bot/ComfyBot.bs.js");

var token = "authtoken=" + Belt_Option.getExn(Js_dict.get(Process.env, "STRIMS_CLIENT_TOKEN"));

console.log("token", token);

ComfyBot$Record.bot({
          token: token
        }).then((function (bot) {
          console.log(bot);
          return Promise.resolve(/* () */0);
        })).catch((function (error) {
        console.log(error);
        return Promise.resolve(/* () */0);
      }));

function hang(param) {
  setTimeout(hang, 50000);
  return /* () */0;
}

exports.token = token;
exports.hang = hang;
/* token Not a pure module */
