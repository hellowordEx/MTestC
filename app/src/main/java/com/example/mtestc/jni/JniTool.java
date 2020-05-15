package com.example.mtestc.jni;

public class JniTool {

    static {
        System.loadLibrary("jniSdk-lib");
    }

    public native int findKey(char[] a, int n, char key);

}
