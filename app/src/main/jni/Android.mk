LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := YanboberJniLibName
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_LDLIBS := \
	-llog \
	-lz \
	-lm \

LOCAL_SRC_FILES := \
	C:\Users\zhanganl\Desktop\Jni_test\jni_test_stdio\jni_test_stdio\app\src\main\jni\jnitest.cpp \

LOCAL_C_INCLUDES += C:\Users\zhanganl\Desktop\Jni_test\jni_test_stdio\jni_test_stdio\app\src\main\jni
LOCAL_C_INCLUDES += C:\Users\zhanganl\Desktop\Jni_test\jni_test_stdio\jni_test_stdio\app\src\debug\jni

include $(BUILD_SHARED_LIBRARY)