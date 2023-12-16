# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCar)

# 遍历所有的子目录
add_subdirectory("Builder Pattern")
add_subdirectory("Decorator Pattern")
add_subdirectory("Facade Pattern")
add_subdirectory("Factory Pattern")
add_subdirectory("Mediator Pattern")
add_subdirectory("Observer Pattern")
add_subdirectory("State Pattern")
add_subdirectory("Chain of Responsibility Pattern")
add_subdirectory("Visitor Pattern")
add_subdirectory("Abstract Factory Pattern")


# 设置编译器选项（可选）
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

