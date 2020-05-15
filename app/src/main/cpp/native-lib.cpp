#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/MyLinkList.h"

#define TAG    "jni-test"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mtestc_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    char* str = new char[1];
    str[0] = '2';
    int len = sizeof(str);
    LOGD("strLen:%d", len);
    delete[](str);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_mtestc_jni_JniTool_findKey(JNIEnv *env, jobject instance,
        jcharArray a_, jint n, jchar key) {
    jchar *a = env->GetCharArrayElements(a_, nullptr);
    int len = env->GetArrayLength(a_);
    LOGD("len:%d",len);
    int keyOfList = find((char*)a, n, (char)key);
    LOGD("keyOfList:%d", keyOfList);
    env->ReleaseCharArrayElements(a_, a, 0);
    return keyOfList;
}