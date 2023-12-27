# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEngeryCarAdapter)

# 添加头文件
set(SOURCES
    Adapter.cpp
)

# 添加静态库
add_library(adapter_lib STATIC ${SOURCES})

# 添加可执行文件，并链接静态库
#add_executable(adapter test.cpp)
#target_link_libraries(adapter PRIVATE adapter_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(adapter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
