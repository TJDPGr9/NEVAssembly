# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarStrategy)

# 添加头文件和源文件
set(SOURCES
    dijkstra.cpp
    utility.cpp
    test.cpp
)
set(HEADERS
    strategy.h
)

# 添加静态库
add_library(strategy_lib STATIC ${SOURCES} ${HEADERS})

# 添加可执行文件，并链接静态库
#add_executable(strategy main.cpp)
#target_link_libraries(strategy PRIVATE straregy_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(strategy_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
