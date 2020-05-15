
#cmake版本号，一般用默认的就好
cmake_minimum_required(VERSION 3.4.1)
#set方法，相当于设置别名，即JniSDK = ${CMAKE_SOURCE_DIR}/
set(JniSDK ${CMAKE_SOURCE_DIR}/)
#设置头文件目录，JniSDK在上面设置的，等于${CMAKE_SOURCE_DIR}
include_directories(${JniSDK}/include
        )

#将JniSDK下面所有的.cpp文件添加到cpp_srcs中
file(GLOB_RECURSE cpp_srcs ${JniSDK}/*.cpp)
#将JniSDK下面所有的.c文件添加到c_srcs中
file(GLOB_RECURSE c_srcs ${JniSDK}/*.c)
#将c_srcs添加到cpp_srcs中
list(APPEND cpp_srcs ${c_srcs})

#将cpp_srcs中的所有.c和.cpp文件添加到库jniSdk-lib中
add_library(jniSdk-lib SHARED ${cpp_srcs})

find_library( # Sets the name of the path variable.
              log-lib
              log )
#生成动态链接库jniSdk-lib
target_link_libraries( # Specifies the target library.
                        jniSdk-lib
                       ${log-lib} )