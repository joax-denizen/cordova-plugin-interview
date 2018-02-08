var exec = require("cordova/exec");

var InterviewSDK = function () {
    this.name = "InterviewSDK";
};

InterviewSDK.prototype.setDelegate = function (onSuccess, onError) {
	exec(onSuccess, onError, "InterviewSDK", "setDelegateMethod");
};

InterviewSDK.prototype.setEngine = function (onSuccess, onError, url, username, password, demoTaskId) {
	exec(onSuccess, onError, "InterviewSDK", "setEngine", [url, username, password, demoTaskId]);
};

InterviewSDK.prototype.setEngineWithKey = function (onSuccess, onError, url, apikey, demoTaskId) {
	exec(onSuccess, onError, "InterviewSDK", "setEngineWithKey", [url, apikey, demoTaskId]);
};

InterviewSDK.prototype.setS3Storage = function (onSuccess, onError, s3url, bucket, accessKey, secretKey) {
	exec(onSuccess, onError, "InterviewSDK", "setS3Storage", [s3url, bucket, accessKey, secretKey]);
};

InterviewSDK.prototype.setAuthString = function (onSuccess, onError, authStr) {
	exec(onSuccess, onError, "InterviewSDK", "setAuthString", [authStr]);
};

InterviewSDK.prototype.showInterview = function (onSuccess, onError, taskId, videoQuality) {
	exec(onSuccess, onError, "InterviewSDK", "showInterview", [taskId, videoQuality]);
};

InterviewSDK.prototype.showDemoInterview = function (onSuccess, onError) {
	exec(onSuccess, onError, "InterviewSDK", "showDemoInterview");
};

module.exports = new InterviewSDK();
