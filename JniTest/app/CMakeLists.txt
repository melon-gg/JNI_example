cmake_minimum_required(VERSION 3.4.1)

add_library( # 设置so文件名称.
             jni-test
             # 设置这个so文件为共享.
             SHARED
             # 设置 c文件源码位置.
             src/main/jni/main.c )