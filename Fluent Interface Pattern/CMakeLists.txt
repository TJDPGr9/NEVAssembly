# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarFluent)

# 添加头文件和源文件
set(SOURCES
    FluentInterface.cpp
    Input.cpp
    main.cpp
)

# 添加静态库
add_library(fluent_lib STATIC ${SOURCES})

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(fluent_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
