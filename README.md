# Discord Bot in ReasonML

![project-logo](RecordLogo.png)
A reasonable discord library

## WebSocket Code Samples

RecordBot is forked from <https://github.com/kfish610/record>, updated deps and added setup notes.

See also:
1. [pocket-mesh](https://github.com/jhrdina/pocket-mesh)
2. [jaredly/reprocessing-scripts/HotServer.re](https://github.com/jaredly/reprocessing-scripts/blob/master/src/HotServer.re)

## Discord Bot Setup

See: <https://discordjs.guide/creating-your-bot/#creating-the-bot-file>
Be sure to get a `token` after adding a bot to your `Discord App`.

## Testing

Setup `bot-settings.json` with `cp bot-settings.example.json bot-settings.json` then go add the `token` you got in your bot setup.

Add [isomorphic-ws](github:isomorphic-ws) then run `node lib/js/test/Test.bs.js`.

Once you run that you should get some out showing you have connected to the `discord` server.

```json
$ node lib/js/test/Test.bs.js
Opened
{
  settings: {
    token: '###########################################################'
  },
  ws: WebSocket {
    _events: [Object: null prototype] {
      open: [Function],
      close: [Function],
      error: [Function],
      message: [Function]
    },
    _eventsCount: 4,
    _maxListeners: undefined,
    readyState: 1,
    protocol: '',
    _binaryType: 'nodebuffer',
    _closeFrameReceived: false,
    _closeFrameSent: false,
    _closeMessage: '',
    _closeTimer: null,
    _closeCode: 1006,
    _extensions: {},
    _receiver: Receiver {
      _writableState: [WritableState],
      writable: true,
      _events: [Object],
      _eventsCount: 6,
      _maxListeners: undefined,
      _binaryType: 'nodebuffer',
      _extensions: {},
      _maxPayload: 104857600,
      _bufferedBytes: 0,
      _buffers: [],
      _compressed: false,
      _payloadLength: 0,
      _mask: undefined,
      _fragmented: 0,
      _masked: false,
      _fin: false,
      _opcode: 0,
      _totalPayloadLength: 0,
      _messageLength: 0,
      _fragments: [],
      _state: 0,
      _loop: false,
      [Symbol(websocket)]: [Circular]
    },
    _sender: Sender {
      _extensions: {},
      _socket: [TLSSocket],
      _firstFragment: true,
      _compress: false,
      _bufferedBytes: 0,
      _deflating: false,
      _queue: []
    },
    _socket: TLSSocket {
      _tlsOptions: [Object],
      _secureEstablished: true,
      _securePending: false,
      _newSessionPending: false,
      _controlReleased: true,
      _SNICallback: null,
      servername: 'gateway.discord.gg',
      alpnProtocol: false,
      authorized: true,
      authorizationError: null,
      encrypted: true,
      _events: [Object],
      _eventsCount: 6,
      connecting: false,
      _hadError: false,
      _parent: null,
      _host: 'gateway.discord.gg',
      _readableState: [ReadableState],
      readable: true,
      _maxListeners: undefined,
      _writableState: [WritableState],
      writable: true,
      allowHalfOpen: false,
      _sockname: null,
      _pendingData: null,
      _pendingEncoding: '',
      server: undefined,
      _server: null,
      ssl: [TLSWrap],
      _requestCert: true,
      _rejectUnauthorized: true,
      parser: null,
      _httpMessage: null,
      timeout: 0,
      [Symbol(res)]: [TLSWrap],
      [Symbol(asyncId)]: 3,
      [Symbol(kHandle)]: [TLSWrap],
      [Symbol(lastWriteQueueSize)]: 0,
      [Symbol(timeout)]: null,
      [Symbol(kBytesRead)]: 0,
      [Symbol(kBytesWritten)]: 0,
      [Symbol(connect-options)]: [Object],
      [Symbol(websocket)]: [Circular]
    },
    _bufferedAmount: 0,
    _isServer: false,
    _redirects: 0,
    url: 'wss://gateway.discord.gg/?v=6&encoding=json',
    _req: null
  }
}
{"t":"READY","s":1,"op":0,"d":{"v":6,"user_settings":{},"user":{"verified":true,"username":"record-bot","mfa_enabled":false,"id":"652653726804344844","email":null,"discriminator":"2261","bot":true,"avatar":null},"session_id":"4ffef2727c91e5ec5c88e653171a4165","relationships":[],"private_channels":[],"presences":[],"guilds":[],"_trace":["[\"gateway-prd-main-gk3s\",{\"micros\":28198,\"calls\":[\"discord-sessions-prd-1-7\",{\"micros\":26632,\"calls\":[\"start_session\",{\"micros\":25171,\"calls\":[\"api-prd-main-vjkg\",{\"micros\":21815,\"calls\":[\"get_user\",{\"micros\":1732},\"add_authorized_ip\",{\"micros\":4},\"get_guilds\",{\"micros\":1394},\"coros_wait\",{\"micros\":1}]}]},\"guilds_connect\",{\"micros\":1,\"calls\":[]},\"presence_connect\",{\"micros\":1140,\"calls\":[]}]}]}]"]}}
[
  [
    {
      v: 6,
      user: [Object],
      privateChannels: [],
      guilds: [],
      sessionId: '4ffef2727c91e5ec5c88e653171a4165',
      trace: [Array],
      shard: 0
    },
    tag: 0
  ],
  tag: 0
]
```
