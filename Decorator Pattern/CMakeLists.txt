# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEngeryCar)

# 添加可执行文件，将头文件和源文件都包含进去
add_executable(decorator decorator.h decorator.cpp)
