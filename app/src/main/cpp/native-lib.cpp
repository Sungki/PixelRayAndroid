#include <jni.h>
#include <string>

extern "C"
{
    void initProgram()
    {
    }

    void Java_com_example_testndk_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jclass thiz, jint w, jint h)
    {
        initProgram();
    }
}