# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarIterator)

# 添加头文件和源文件
set(SOURCES
    Iterator.cpp
    RailwayBureaus.cpp
    test.cpp
)

# 添加静态库
add_library(iterator_lib STATIC ${SOURCES})

# 添加可执行文件，并链接静态库
#add_executable(iterator "test.cpp")
#target_link_libraries(iterator PRIVATE iterator_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(iterator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
