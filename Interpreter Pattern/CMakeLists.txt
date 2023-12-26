# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置项目名称
project(NewEnergyCarInterpretor)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include/json)
configure_file(data.json ${CMAKE_CURRENT_BINARY_DIR}/data.json COPYONLY)
# 添加头文件和源文件
#add_executable(interpretor VIN.cpp)  
#target_link_libraries(interpretor PRIVATE nlohmann_json::nlohmann_json)
set(SOURCES
    VIN.cpp
)
# CMakeLists.txt
add_library(interpretor_lib STATIC ${SOURCES} )
target_link_libraries(interpretor_lib PRIVATE nlohmann_json::nlohmann_json)
# 添加静态库
