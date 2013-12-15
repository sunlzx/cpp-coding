#include "jni_jnitest.h"

#include <stdio.h>

JNIEXPORT jint JNICALL Java_jni_JniTest_add(JNIEnv *env, jclass jcls, jint n1, jint n2){
    printf("%d * %d \n", n1, n2);
    return n1 * n2;
}
