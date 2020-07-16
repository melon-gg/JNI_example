package com.simon;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.content.Intent;
import android.app.PendingIntent;
import android.widget.Toast;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import java.io.*;
import java.lang.Thread;
import android.view.KeyEvent;
public class ExtendsQtWithJava extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static NotificationManager m_notificationManager;
    private static ExtendsQtWithJava m_instance;
//    private static Handler m_handler = new Handler() {
//        @Override
//        public void handleMessage(Message msg){
//            switch(msg.what){
//            case 1:
//            Toast toast = Toast.makeText(m_instance,(String)msg.obj,Toast.LENGTH_SHOAT);
//            toast.show();
//            break;
//            }
//        }
//    }

    private static int pageIdx = 0;
    public static native String GetQtVersion();
    public boolean onKeyDown(int keyCode, KeyEvent event) {

    if(keyCode == KeyEvent.KEYCODE_BACK && pageIdx == 0){
        moveTaskToBack(true);
        Log.v("vlog","move task to back!");
        return true;
    }
    else
    {
        pageIdx = 0;
        ExtendsQtWithNative.BackKeyPress();
        Log.v("vlog", "do nothing");
        Log.v("vlog", pageIdx + "");
        return true;
    }
    //return super.onKeyDown(keyCode, event);
}
    public static String setPageIdx(int idx) {
            pageIdx = idx;
            Log.v("vlog", pageIdx + "");
            return "";
        }
    public static void printVLog(String log){
        Log.v("vlog", log);
        //return "";
    }
    public static String printQtVersion(){
        String s = ExtendsQtWithNative.GetQtVersion();
        Log.v("vlog", s);
        return "";
        }
};
