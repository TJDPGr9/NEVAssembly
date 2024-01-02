# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEngeryCarDecorator)

# 添加头文件
set(SOURCES
    decorator.cpp
)

# 添加静态库
add_library(decorator_lib STATIC ${SOURCES})

# 添加可执行文件，并链接静态库
add_executable(decorator real.cpp)
target_link_libraries(decorator PRIVATE decorator_lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(decorator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
