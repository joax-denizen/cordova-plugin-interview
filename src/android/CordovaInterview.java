package com.interview.korul.interview;

import com.interview.korul.interview.Utility.Constants;
import com.interview.korul.interview.*;
import com.interview.korul.interview.InterView;
import com.interview.korul.interview.Utility.InterfaceScheme;
import com.interview.korul.interview.Utility.VideoQuality;
import com.interview.korul.interview.Model.SubTask;
import com.interview.korul.interview.Model.Task;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Resources;
import com.interview.korul.interview.Model.SubTask;
import com.interview.korul.interview.Model.Task;
import com.interview.korul.interview.Utility.Constants;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import java.io.ByteArrayOutputStream;
import java.util.ArrayList;

import org.apache.cordova.*;
import org.json.JSONArray;
import org.json.JSONException;
import android.widget.Toast;


public class CordovaInterview extends CordovaPlugin{

    InterView interview = new InterView();
    Constants Const = new Constants();

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        // your init code here

    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (action.equals("setEngine")){
	   // Toast.makeText(cordova.getActivity().getApplicationContext(),"setEngine",Toast.LENGTH_LONG).show();
            setEngine(args);
            callbackContext.success();
        } else if (action.equals("showInterview")){
	  //  Toast.makeText(cordova.getActivity().getApplicationContext(),"showInterview",Toast.LENGTH_LONG).show();
            showInterview(args);
            callbackContext.success();
        } else if (action.equals("showDemoInterview")){
	  //  Toast.makeText(cordova.getActivity().getApplicationContext(),"showDemoInterview",Toast.LENGTH_LONG).show();
            showDemoInterview();
            callbackContext.success();
        } else {
            //Toast.makeText(cordova.getActivity().getApplicationContext(),"unknown method",Toast.LENGTH_LONG).show();
            callbackContext.error("unknown method");
        }

        return true;  // Returning false results in a "MethodNotFound" error.
    }


    private void setEngine(JSONArray params){
        String url ="";
        String username ="";
        String password = "";
        String demoTaskId="";

        try {
            url = params.getString(0);
            username = params.getString(1);
            password = params.getString(2);
            demoTaskId = params.getString(3);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        interview.setEngineURL(url, username, password, demoTaskId);
    }

    private void showDemoInterview(){

        InterfaceScheme Interfacescheme = com.interview.korul.interview.Utility.InterfaceScheme.InterviewInterfaceSchemeBlack;
        interview.set_INTERFACESCHEME(Interfacescheme);

        interview.set_IS_TUTORIAL(true);
        interview.set_CLOSE_BUTTON(true);
        interview.set_RESTART_BUTTON(false);

        interview.set_VIDEO_QUALITY(VideoQuality.QUALITY.QUALITY_HIGH);

        interview.set_IS_AUTOLOAD(true);
        interview.set_IS_AUTOCLOSE(true);

        Task task = new Task();
        task.setTask(true);

        SubTask subtask = new SubTask();
        subtask.setOVERLAYTYPE(Const.FACE());
        subtask.setTITLE      ("DEMO MODE");
        subtask.setSUBTITLE   ("Use the link in your mailbox to go through a personalized interview process");
        subtask.setTYPE       (Const.DEMO());
        subtask.setMINTIME    (0);
        subtask.setMAXTIME    (0);
        subtask.setOBJECT_ID  ("1");

        SubTask subtask1 = new SubTask();
        subtask1.setOVERLAYTYPE(Const.FACE());
        subtask1.setTITLE      ("Read the numbers outloud facing the camera");
        subtask1.setPREFACE    ("Face the camera and press 'Record'");
        subtask1.setSUBTITLE   ("16854654");
        subtask1.setTYPE       (Const.READ_CODE());
        subtask1.setMINTIME    (5);
        subtask1.setMAXTIME    (15);
        subtask1.setOBJECT_ID  ("2");

        SubTask subtask2 = new SubTask();
        subtask2.setOVERLAYTYPE(Const.PASSPORT());
        subtask2.setTITLE      ("Document recording");
        subtask2.setPREFACE    ("Center the passport here and then press 'Record'");
        subtask2.setSUBTITLE   ("Please wait until recording continues");
        subtask2.setTYPE       (Const.SHOW_PASSPORT());
        subtask2.setORIENTATION(Const.LANDSCAPE());
        subtask2.setIS_REAR_CAMERA(true);
        subtask2.setMINTIME    (5);
        subtask2.setMAXTIME    (5);
        subtask2.setOBJECT_ID  ("3");

        ArrayList<SubTask> sub = new ArrayList<SubTask>();
        sub.add(0, subtask);
        sub.add(1, subtask1);
        sub.add(2, subtask2);
        task.setSUBTASK(sub);

        task.setConfirmType(false);

        interview.setDemoTask(task);

        interview.showInterView(cordova.getActivity().getApplicationContext(), "", "");
    }

    private void showInterview(JSONArray params){

        String demoTaskId="";
        try {
            demoTaskId = params.getString(3);
        } catch (JSONException e) {
            e.printStackTrace();
        }

        InterfaceScheme Interfacescheme = com.interview.korul.interview.Utility.InterfaceScheme.InterviewInterfaceSchemeDark;
        interview.set_INTERFACESCHEME(Interfacescheme);

        interview.set_IS_TUTORIAL(false);
        interview.set_isPortraitLoadingScreen(true);
        interview.set_CLOSE_BUTTON(true);
        interview.set_RESTART_BUTTON(false);
        interview.set_IS_AUTOLOAD(true);
        interview.set_IS_AUTOCLOSE(true);
        interview.set_TASK_ID(demoTaskId);
        interview.set_loadingScreenType(true);

        interview.set_VIDEO_QUALITY(VideoQuality.QUALITY.QUALITY_HIGH);
        interview.setDemoTask(interview.getDefaultTask());

        String taskId ="";
        String videoQualityString="";
        try {

            taskId = params.getString(0);
            videoQualityString  = params.getString(1).toLowerCase();
        } catch (JSONException e) {
            e.printStackTrace();
        }

        VideoQuality.QUALITY videoQuality;

        if(videoQualityString.equals("interviewvideoqualitylow") || videoQualityString.equals("low")){
            videoQuality = VideoQuality.QUALITY.QUALITY_LOW;
        } else if (videoQualityString.equals("interviewvideoqualitymedium") || videoQualityString.equals("medium")) {
            videoQuality = VideoQuality.QUALITY.QUALITY_HIGH;
        } else if (videoQualityString.equals("interviewvideoqualityhigh") || videoQualityString.equals("high")) {
            videoQuality = VideoQuality.QUALITY.QUALITY_HIGH;
        } else {
            videoQuality = VideoQuality.QUALITY.QUALITY_HIGH;
        };

        interview.set_VIDEO_QUALITY(videoQuality);
        interview.showInterView(cordova.getActivity().getApplicationContext(),taskId,"");
    }
}
