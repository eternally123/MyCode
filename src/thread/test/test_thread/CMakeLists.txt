include_directories(${CMAKE_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin) #设置生成库文件位置在/build/lib

add_executable(thread_test thread_test.cc)

target_link_libraries(thread_test thread pthread)
