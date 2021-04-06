#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
{
    void initProgram()
    {
        __android_log_print(ANDROID_LOG_VERBOSE, "TestNDK", "initProgram");
    }

    void Java_com_example_testndk_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jclass thiz, jint w, jint h)
    {
        initProgram();

        __android_log_print(ANDROID_LOG_VERBOSE, "TestNDK", "My Log");
    }
}