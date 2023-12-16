# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarAbstract)

# 添加头文件和源文件
set(SOURCES
    Car.cpp
    CarBuilder.cpp
    Director.cpp
    main.cpp
)

# 添加可执行文件
add_executable(abstract ${SOURCES})

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(abstract PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 设置编译器选项（可选）
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
