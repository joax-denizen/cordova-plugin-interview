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

InterviewSDK.prototype.showInterview = function (onSuccess, onError, taskId, videoQuality) {
	exec(onSuccess, onError, "InterviewSDK", "showInterview", [taskId, videoQuality]);
};

InterviewSDK.prototype.showDemoInterview = function (onSuccess, onError) {
	exec(onSuccess, onError, "InterviewSDK", "showDemoInterview");
};

module.exports = new InterviewSDK();