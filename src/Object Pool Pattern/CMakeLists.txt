# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)
# 设置项目名称
project(NewEngeryOP)
# 添加可执行文件，并链接静态库
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(objectpool main.cpp)