# cordova-plugin-interview

Native plugin for blockchain-based video-interviews.

Uses InterviewSDK v2.4.1

Only for iOS (minimum version 8.0)

This plugin cannot work on simulator, because it uses some device-specific capablities (camera, microphone etc)

## Installation

```
npm install https://github.com/aabluedragon/node-xcode.git
cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git
cordova plugin add cordova-plugin-disable-bitcode --save
```

## Usage

```

// Demo mode
interview.showInterview(onSuccess, onError);

```