//
// Created by wenguo on 2020/5/11.
//

#include <android/log.h>

#include "include/MylinkList.h"

#define TAG    "jni-test"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

int find(char *a, int n, char key)
{
    //边界条件处理，如果a为空，或者n<=0，说明数组中没有数据，直接返回-1.
    if (nullptr == a || n <= 0)
    {
        return -1;
    }
    int i = 0;
    while (i < n)
    {
        LOGD("a[%d]=%c",i,a[i]);
        if (key == a[i])
        {
            return i/2;
        }
        //java中，char是16位，占两个字节，C++中，char是8位，占一个字节，所以这里要+2，同理返回时要/2.
        i+=2;
    }
    return -1;
}

int find_2(char *a, int n, char key)
{
    return -1;
}
