#include "sample1.h"
#include <string.h>
#include <stdlib.h>
JNIEXPORT jint JNICALL Java_jni_Sample1_intMethod
(JNIEnv *env, jobject obj, jint num) {
    return num * num;
}

JNIEXPORT jboolean JNICALL Java_jni_Sample1_booleanMethod
(JNIEnv *env, jobject obj, jboolean boolean) {
    return !boolean;
}


JNIEXPORT jstring JNICALL Java_jni_Sample1_stringMethod
(JNIEnv *env, jobject obj, jstring string) {
    jboolean isCopy = JNI_TRUE;
    const char *str = (*env)->GetStringUTFChars(env, string, &isCopy);
    char cap[128];
    strcpy(cap, str);
    strcat(cap, " hello");

    (*env)->ReleaseStringUTFChars(env, string, str);
    //    return (*env)->NewStringUTF(env, strupr(cap));

    return (*env)->NewStringUTF(env, cap);
}

JNIEXPORT jint JNICALL Java_jni_Sample1_intArrayMethod
(JNIEnv *env, jobject obj, jintArray array) {
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for (i=0; i<len; i++)
    {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, array, body, 0);
    return sum;
}


/*
 * Class:     jni_Sample1
 * Method:    intArrayMethod2
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_jni_Sample1_intArrayMethod2
(JNIEnv *env, jobject jobj, jintArray array) {
    int i;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for (i=0; i<len; i++)
    {
        body[i] = body[i] * 2;
    }
    (*env)->ReleaseIntArrayElements(env, array, body, 0);
    return array;

//    return a new array
//    jsize nsize = 10;
//    jintArray newArray = (*env)->NewIntArray(env, nsize);
//    return array;
}

void  main(){}
