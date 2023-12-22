# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置项目名称
project(NewEnergyCarInterpretor)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/json)
# 添加头文件和源文件
add_executable(interpretor VIN.cpp)  
target_link_libraries(interpretor PRIVATE nlohmann_json::nlohmann_json)

