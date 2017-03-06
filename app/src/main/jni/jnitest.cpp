//
// Created by zhanganl on 2017/2/20.
//
#include "com_sample_zhanganl_ndkjnidemo3_NdkJniUtils.h"
#include <string.h>
#include <stdio.h>
/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_getCLanguageString
  (JNIEnv *env, jobject obj,jstring aa){
     char cc[100]="i am zhang";
     const char* bb = env->GetStringUTFChars(aa, JNI_FALSE);
     strcat(cc,bb);
     env->ReleaseStringUTFChars(aa, bb);
     return env->NewStringUTF(cc);
  }
JNIEXPORT jint JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_sum
        (JNIEnv *env, jobject obj,jintArray arr)
{
   int buf[100000];
   int i, sum = 0;
   env->GetIntArrayRegion( arr, 0, 100000, buf);
   for (i = 0; i < 100000; i++) {
      sum += buf[i];
   }
   return sum;
}

JNIEXPORT jobjectArray JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_initInt2DArray
        (JNIEnv *env, jclass cls, int size)
{
    jobjectArray result;
    int i;
    jclass intArrCls = env->FindClass("[I");
    if (intArrCls == NULL) {
        return NULL; /* exception thrown */
    }
    result = env->NewObjectArray(size, intArrCls, NULL);
    if (result == NULL) {
        return NULL; /* out of memory error thrown */
    }
    for (i = 0; i < size; i++) {
        jint tmp[256]; /* make sure it is large enough! */
        int j;
        jintArray iarr = env->NewIntArray(size);
        if (iarr == NULL) {
            return NULL; /* out of memory error thrown */
        }
        for (j = 0; j < size; j++) {
            tmp[j] = i + j;
        }
        env->SetIntArrayRegion(iarr, 0, size, tmp);
        env->SetObjectArrayElement(result, i, iarr);
        env->DeleteLocalRef(iarr);
    }
    return result;
}

//Accessing Fields
JNIEXPORT void JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_accessField
        (JNIEnv *env, jobject obj)
{
    jfieldID fid; /* store the field ID */
    jstring jstr;
    const char *str;
/* Get a reference to obj’s class */
    jclass cls = env->GetObjectClass(obj);
    printf("In C:\n");
/* Look for the instance field s in cls */
    fid = env->GetFieldID(cls, "s", "Ljava/lang/String;");
    if (fid == NULL) {
        return; /* failed to find the field */
    }
/* Read the instance field s */
    jstr = (jstring)env->GetObjectField(obj, fid);
    str = env->GetStringUTFChars(jstr, NULL);
    if (str == NULL) {
        return; /* out of memory */
    }
    printf(" c.s = \"%s\"\n", str);
    env->ReleaseStringUTFChars(jstr, str);
/* Create a new string and overwrite the instance field */
    jstr = env->NewStringUTF("123");
    if (jstr == NULL) {
        return; /* out of memory */
    }
    env->SetObjectField(obj, fid, jstr);
}

//Accessing static Fields
JNIEXPORT void JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_accessStaticField
        (JNIEnv *env, jobject obj)
{
    jfieldID fid; /* store the field ID */
    jint si;
/* Get a reference to obj’s class */
    jclass cls = env->GetObjectClass(obj);
    printf("In C:\n");
/* Look for the static field si in cls */
    fid = env->GetStaticFieldID(cls, "n", "I");
    if (fid == NULL) {
        return; /* field not found */
    }
/* Access the static field si */
    si = env->GetStaticIntField(cls, fid);
    printf(" StaticFieldAccess.si = %d\n", si);
    env->SetStaticIntField(cls, fid, 200);
}

//Calling Methods
JNIEXPORT void JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_nativeMethod
        (JNIEnv *env, jobject obj)
{
    jclass cls = env->GetObjectClass(obj);
    jmethodID mid = env->GetMethodID(cls, "callback", "()V");
    if (mid == NULL) {
        return; /* method not found */
    }
    printf("In C\n");
    env->CallVoidMethod(obj, mid);
}

//call construct method
JNIEXPORT void JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_accessConstructMethod
        (JNIEnv *env, jobject obj)
{
    //1.获取com.sample.zhanganl.ndkjnidemo3.NdkJniUtils目录下NdkJniUtils的jclass
    jclass  cls = env->FindClass("com/sample/zhanganl/ndkjnidemo3/NdkJniUtils");
    //2.获取NdkJniUtils的构造函数ID
    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
    //3.初始化构造函数(此处传递了参数)
    jobject jniDemo = env->NewObject(cls, mid, env->NewStringUTF("小明"), 10);
    //4.获取NdkJniUtils的feildPrint方法ID
    jmethodID pritid = env->GetMethodID(cls, "feildPrint", "()V");
    //5.调用NdkJniUtils的feildPrint方法
    env->CallVoidMethod(jniDemo, pritid);
}

//call parent method
JNIEXPORT void JNICALL Java_com_sample_zhanganl_ndkjnidemo3_NdkJniUtils_accessParentMethod
        (JNIEnv *env, jobject obj)
{
    //1.获取NdkJniUtils的jclass
    jclass jcls = env->FindClass("com/sample/zhanganl/ndkjnidemo3/NdkJniUtils");
    //2.获取NdkJniUtils的构造方法ID
    jmethodID mid = env->GetMethodID(jcls, "<init>", "(Ljava/lang/String;I)V");
    //3.实例化NdkJniUtils并传递参数
    jobject jcobj = env->NewObject(jcls, mid, env->NewStringUTF("小学生"), 5);
    //4.获取父类的NdkJniUtilsParent
    jclass jpcls = env->FindClass("com/sample/zhanganl/ndkjnidemo3/NdkJniUtilsParent");
    //5.获取子类的eat方法ID
    jmethodID peatID = env->GetMethodID(jcls, "eat", "()V");
    //直接调用子类方法
//    env->CallVoidMethod(jcobj, peatID);
    //6.调用父类方法
    env->CallNonvirtualVoidMethod(jcobj, jpcls, peatID);
}
