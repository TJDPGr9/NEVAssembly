# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarFlyWeight)

# 添加头文件
set(SOURCES
    flyweight.cpp
)

# 添加静态库
add_library(flyweight_lib STATIC  ${SOURCES})

# 添加可执行文件，并链接静态库
add_executable(flyweight real.cpp)
target_link_libraries(flyweight PRIVATE flyweight_lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(flyweight_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
