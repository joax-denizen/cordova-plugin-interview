var exec = require("cordova/exec");

var InterviewSDK = function () {
    this.name = "InterviewSDK";
};

InterviewSDK.prototype.showDemoInterview = function (onSuccess, onError) {
	exec(onSuccess, onError, "InterviewSDK", "showDemoInterview");
};

module.exports = new InterviewSDK();