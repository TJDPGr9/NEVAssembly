# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCarSpecification)

# 添加头文件和源文件
set(SOURCES
    CarPart.hpp
    specification_template.hpp
    specifications.hpp
)

# 添加静态库
add_library(specification_lib STATIC  ${SOURCES} ../empty.cpp)

# 添加可执行文件，并链接静态库
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(specification test.cpp)
target_link_libraries(specification PRIVATE specification_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(specification_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
