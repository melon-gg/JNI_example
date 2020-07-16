#my-dir:返回当前 Android.mk 所在的目录的路径
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# 定义生成so文件的名字
LOCAL_MODULE := hello-jni
# 需要编译的文件，由于在一个文件夹下，不用写路径
LOCAL_SRC_FILES := main.c

include $(BUILD_SHARED_LIBRARY)
# 指定生成全部的ABI的so文件
APP_ABI := all