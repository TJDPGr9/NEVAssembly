# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEngeryCarVisitor)

# 添加头文件
set(HEADERS
    visitor.h
)
set(SOURCES
    test.cpp
)
# 添加静态库
add_library(visitor_lib STATIC ${HEADERS} ${SOURCES})

# 添加可执行文件，并链接静态库
#add_executable(visitor inte.cpp)
#target_link_libraries(visitor PRIVATE visitor_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(visitor_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
