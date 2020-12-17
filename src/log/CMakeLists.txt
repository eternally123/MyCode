cmake_minimum_required(VERSION 2.8)
project(log)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib) #设置生成库文件位置在/build/lib
aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCE_FILES)

add_library(log SHARED ${SOURCE_FILES}) # 最终生动态链接库
add_library(log_static STATIC ${SOURCE_FILES}) # 最终生成静态链接库
set_target_properties(log_static PROPERTIES OUTPUT_NAME "log")

file(GLOB head_files ${CMAKE_SOURCE_DIR}/src/*.hh)

install(FILES  ${head_files} DESTINATION  ${CMAKE_SOURCE_DIR}/install/include/log)
install(TARGETS log DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)
install(TARGETS log_static DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)