// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Json = require("@glennsl/bs-json/lib/js/src/Json.bs.js");
var Json_decode = require("@glennsl/bs-json/lib/js/src/Json_decode.bs.js");
var Caml_js_exceptions = require("bs-platform/lib/js/caml_js_exceptions.js");

function decodeRedditPostData(json) {
  return {
          url: Json_decode.field("url", Json_decode.string, json)
        };
}

function decodeRedditPost(json) {
  return {
          data: Json_decode.field("data", decodeRedditPostData, json),
          kind: Json_decode.field("kind", Json_decode.string, json)
        };
}

function decodeRedditResponseData(json) {
  return {
          after: Json_decode.field("after", Json_decode.string, json),
          before: Json_decode.optional((function (param) {
                  return Json_decode.field("before", Json_decode.string, param);
                }), json),
          children: Json_decode.field("children", (function (param) {
                  return Json_decode.list(decodeRedditPost, param);
                }), json),
          modhash: Json_decode.field("modhash", Json_decode.string, json)
        };
}

function decodeRedditResponse(json) {
  return {
          data: Json_decode.field("data", decodeRedditResponseData, json),
          kind: Json_decode.field("kind", Json_decode.string, json)
        };
}

function parseRedditResponse(json) {
  return decodeRedditResponse(Json.parseOrRaise(json));
}

function fetchRedditPosts(param) {
  return fetch("https://www.reddit.com/r/cozyplaces.json").then((function (prim) {
                  return prim.text();
                })).then((function (text) {
                var json;
                try {
                  json = decodeRedditResponse(Json.parseOrRaise(text));
                }
                catch (raw_e){
                  return Promise.reject(Caml_js_exceptions.internalToOCamlException(raw_e));
                }
                return Promise.resolve(json.data.children);
              }));
}

exports.decodeRedditPostData = decodeRedditPostData;
exports.decodeRedditPost = decodeRedditPost;
exports.decodeRedditResponseData = decodeRedditResponseData;
exports.decodeRedditResponse = decodeRedditResponse;
exports.parseRedditResponse = parseRedditResponse;
exports.fetchRedditPosts = fetchRedditPosts;
/* No side effect */
