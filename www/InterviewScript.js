var exec = require("cordova/exec");

var InterviewSDK = function () {
    this.name = "InterviewSDK";
};

InterviewSDK.prototype.showInterview = function (onSuccess, onError, taskId) {
    exec(onSuccess, onError, "InterviewSDK", "showInterview", taskId);
};

module.exports = new InterviewSDK();