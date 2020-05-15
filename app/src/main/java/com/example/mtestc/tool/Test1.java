package com.example.mtestc.tool;

import com.example.mtestc.jni.JniTool;

public class Test1 {

    public static int find() {
        char[] chars = new char[]{'h', 'e', 'l', 'l', 'o'};
        JniTool jniTool = new JniTool();
        return jniTool.findKey(chars, chars.length*2, 'o');
    }

}
