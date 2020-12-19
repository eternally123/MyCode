cmake_minimum_required(VERSION 2.8)
project(test)

include_directories(${CMAKE_SOURCE_DIR}/../src)
include_directories(${CMAKE_SOURCE_DIR}/../third_party/log/include)
link_directories(${CMAKE_SOURCE_DIR}/../third_party/log/lib)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib) #设置生成库文件位置在/build/lib
set(../src ${SRC_LIST})


add_executable(thread_test src/thread_test.cc ${SRC_LIST})

target_link_libraries(thread_test -lpthread -llog)
