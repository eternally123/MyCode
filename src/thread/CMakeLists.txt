cmake_minimum_required(VERSION 2.8)
project(thread)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib) #设置生成库文件位置在/build/lib
aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCE_FILES)

add_library(thread SHARED ${SOURCE_FILES}) # 最终生动态链接库
add_library(thread_static STATIC ${SOURCE_FILES}) # 最终生成静态链接库
set_target_properties(thread_static PROPERTIES OUTPUT_NAME "thread")

file(GLOB head_files ${CMAKE_SOURCE_DIR}/src/*.hh)

install(FILES  ${head_files} DESTINATION  ${CMAKE_SOURCE_DIR}/install/include)
install(TARGETS thread DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)
install(TARGETS thread_static DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)