# cordova-plugin-interview

Native plugin for blockchain-based video-interviews.

Uses InterviewSDK v2.0.1

Only for iOS (minimum version 8.0)

## Installation

```
cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git
cordova plugin add cordova-plugin-disable-bitcode --save
```

## Usage

```
// With concrete taskId
interview.showInterview(onSuccess, onError, "taskId");

// Demo mode
interview.showInterview(onSuccess, onError);

```