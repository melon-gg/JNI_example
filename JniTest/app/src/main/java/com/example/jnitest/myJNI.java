package com.example.jnitest;

public class myJNI {
    static {
        System.load("JniTest");
    }

    /**
     * @return
     */
    public static native  String sayHello();
}
