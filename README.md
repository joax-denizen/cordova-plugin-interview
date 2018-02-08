# cordova-plugin-interview

Native plugin for blockchain-based video-interviews.

Uses InterviewSDK v2.11

## Plugin for iOS (minimum version 8.4) and Android (Api 19)

This plugin cannot work on simulator, because it uses some device-specific capablities (camera, microphone etc)

## Installation for iOS

```
npm install https://github.com/aabluedragon/node-xcode.git
cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git
cordova plugin add cordova-plugin-disable-bitcode --save
```

## Installation for Android

```
1. install Android SDK, JRE, JDK
2. make sure that the environment variable is set correctly
3. For Windows install Node.js and run it
4. If the project was not made on Windows run 'npm rebuild node-sass --force'

5. npm install -g ionic@latest
6. npm install -g cordova
7. ionic cordova plugin add https://gitlab.com/blocknotary/cordova-plugin-interview.git --force
8. ionic cordova prepare --force
9. ionic cordova build android --force
```


## Usage



You can simply request demo-interview without any parameters. Specify only callback routines for result processing.

```
// Demo mode
interview.showDemoInterview(onSuccess, onError);

// Success callback routine (returns dictionary with interview result)
function onSuccess(taskDictionary) {
	alert('Interview has just been completed');
}

//Error callback (returns string with error description)
function onFail(error) {
	alert('Failed because: ' + message);
}
```

If you want to set a custom API backend, use the following method. In addition to the URL you must specify username with password to login and demo taskId. Interviews from all demo tasks will be uploaded for this taskId. 

`DEPRECATED METHOD! Use interview.setEngineWithKey instead!`

```
// Setting API backend to the SDK
interview.setEngine(onSuccess, onError, 'https://engine_server.com/', 'username', 'password', 'demo_taskId');
```

For security reasons you could use another method without username and password. This method take user API-key instead user credentials. You can download and upload your tasks with this API-key but full access to the account will be disabled.

```
// Security setting API backend to the SDK
interview.setEngineWithKey(onSuccess, onError, 'https://engine_server.com/', 'api-key', 'demo_taskId');
```


To show an interview with the specified identifier and the quality of the output video, you can use the following method. The video quality parameter is a string that can assume the following values (case-insensitive):

 - `'InterviewVideoQualityLow'` or `'low'` - the worst quality with a minimum upload size
 - `'InterviewVideoQualityMedium'` or `'medium'` - the normal quality with a medium upload size
 - `'InterviewVideoQualityHigh'` or `'high'` - the best quality with a large upload size

```
// Show interview with the specified taskId and output video quality
interview.showInterview(onSuccess, onError, 'taskId', 'medium');
```

You can set additional authorization header to pass it to all API methods. If you set this option SDK will add this header to the all API requests. Use this field for any additional credentials, keys, etc. Currently Basic, Bearer or BNSession authorization types supports only.

```
// Use Basic Authorization header (aladdin:opensesame) for all API requests 
interview.setAuthString(onSuccess, onError, 'Basic YWxhZGRpbjpvcGVuc2VzYW1l');
// Use Bearer Authorization header for all API requests
interview.setAuthString(onSuccess, onError, 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1dWlkIjoiYzcwM2F');
```

The SDK uploads all interview files at its own internal storage by default. If you would to store interview video/audio/screenshot files into you own storage you can override default storage settings. SDK currently supports S3-compatible storages with Static authentication method (apikey+secretkey). Please use the below method for changing internal storage to the user-specific external storage before starting an interview.

```
// Use Static authorization fields (access_key + secret_key)
interview.setS3Storage(onSuccess, onError, 'https://s3.mydomain.com', 'bucket_name', 'access_key', 'secret_key');
```