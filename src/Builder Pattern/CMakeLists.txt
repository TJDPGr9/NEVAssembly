# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarBuilder)

# 添加头文件和源文件
set(SOURCES
    Car.cpp
    CarBuilder.cpp
    Director.cpp
    test.cpp
)

# 添加静态库
add_library(builder_lib STATIC ${SOURCES})

# 添加可执行文件，并链接静态库
#add_executable(builder "test.cpp")
#target_link_libraries(builder PRIVATE builder_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(builder_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
