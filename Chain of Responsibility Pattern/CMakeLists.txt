# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEngeryCarChain)

# 添加头文件
set(HEADERS
    responsibility.h
)
set(SOURCES
    responsibility_chain.cpp
)
# 添加静态库
add_library(chain_lib STATIC  ${HEADERS} ${SOURCES})

# 添加可执行文件，并链接静态库
#add_executable(chain responsibility_chain.cpp)
#target_link_libraries(chain PRIVATE chain_lib)

# 如果有其他的头文件目录，可以使用 target_include_directories 添加
target_include_directories(chain_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
