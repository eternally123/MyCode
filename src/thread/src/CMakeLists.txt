cmake_minimum_required(VERSION 2.8)

# ==========================环境设置============================
# 设置生成库文件位置在/build/lib
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib) 

# 项目头文件位置
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
# ==========================编译文件============================
# 项目源文件
aux_source_directory(utils UTILS_SRC)
aux_source_directory(thread THREAD_SRC)
aux_source_directory(log LOG_SRC)
set(SOURCE_FILES ${UTILS_SRC} ${THREAD_SRC} ${LOG_SRC})



# ==========================安装设置============================
# 指定最后生成静态库与动态库
add_library(thread SHARED ${SOURCE_FILES}) # 最终生动态链接库
add_library(thread_static STATIC ${SOURCE_FILES}) # 最终生成静态链接库
set_target_properties(thread_static PROPERTIES OUTPUT_NAME "thread")


# 头文件安装
file(GLOB head_files ${CMAKE_SOURCE_DIR}/src/log/*.hh)
install(FILES  ${head_files} DESTINATION  ${CMAKE_SOURCE_DIR}/install/include/thread/log)
file(GLOB head_files ${CMAKE_SOURCE_DIR}/src/thread/*.hh)
install(FILES  ${head_files} DESTINATION  ${CMAKE_SOURCE_DIR}/install/include/thread/thread)
file(GLOB head_files ${CMAKE_SOURCE_DIR}/src/utils/*.hh)
install(FILES  ${head_files} DESTINATION  ${CMAKE_SOURCE_DIR}/install/include/thread/utils)

# 库安装
install(TARGETS thread DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)
install(TARGETS thread_static DESTINATION  ${CMAKE_SOURCE_DIR}/install/lib)

