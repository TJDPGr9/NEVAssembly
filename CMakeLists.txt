# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(NewEnergyCar)

# 遍历所有的子目录
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory("src/Builder Pattern")
add_subdirectory("src/Decorator Pattern")
add_subdirectory("src/Facade Pattern")
add_subdirectory("src/Factory Pattern")
add_subdirectory("src/Mediator Pattern")
add_subdirectory("src/Observer Pattern")
add_subdirectory("src/State Pattern")
add_subdirectory("src/Chain of Responsibility Pattern")
add_subdirectory("src/Visitor Pattern")
add_subdirectory("src/Abstract Factory Pattern")
add_subdirectory("src/Prototype Pattern")
add_subdirectory("src/Iterator Pattern")
add_subdirectory("src/Flyweight Pattern")
add_subdirectory("src/Strategy Pattern")
add_subdirectory("src/Interpreter Pattern")
add_subdirectory("src/Command Pattern")
add_subdirectory("src/Adapter Pattern")
add_subdirectory("src/Object Pool Pattern")
add_subdirectory("src/Fluent Interface Pattern")
add_subdirectory("src/Specification Pattern")
link_directories("src/Interpreter Pattern")
#link_libraries("Interpreter Pattern/include/json")
# 设置编译器选项（可选）
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/Release")
configure_file(SDL2.dll ${CMAKE_SOURCE_DIR}/bin/SDL2.dll COPYONLY)
configure_file(SDL2_ttf.dll ${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll COPYONLY)
configure_file("src/Interpreter Pattern/data.json" ${CMAKE_SOURCE_DIR}/bin/data.json COPYONLY)
else()
configure_file(SDL2.dll ${CMAKE_SOURCE_DIR}/bin/Release/SDL2.dll COPYONLY)
configure_file(SDL2_ttf.dll ${CMAKE_SOURCE_DIR}/bin/Release/SDL2_ttf.dll COPYONLY)
configure_file("src/Interpreter Pattern/data.json" ${CMAKE_SOURCE_DIR}/bin/Release/data.json COPYONLY)
endif()
set(SDL2_DEVEL_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/SDL2-2.28.5)
set(SDL2_TTF_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_ttf-2.20.2)
set(JSON_DIRECTORIES "src/Interpreter Pattern/include/json/single_include")
message(${CMAKE_CURRENT_SOURCE_DIR})
#VC++ Direcotories/Include Directories&Library Directories
include_directories(${SDL2_DEVEL_DIRECTORIES}/include ${SDL2_TTF_DIRECTORIES}/include )
link_directories(${SDL2_DEVEL_DIRECTORIES}/lib/x64 ${SDL2_TTF_DIRECTORIES}/lib/x64)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(main main.cpp  "src/style.cpp")
#Subsystem:(/SUBSYSTEM:WINDOWS)
set_target_properties(main PROPERTIES WIN32_EXECUTABLE TRUE)
#C/C++->Preprocessor->preprocessor definition:+_WINDOWS -_CONSOLE
target_compile_definitions(main PRIVATE _WINDOWS)
remove_definitions(-D_CONSOLE)
#Linker->Input->Additional Dependencies/In case of unknown entry _SDL_MAIN
target_link_libraries(main PRIVATE ${SDL2_DEVEL_DIRECTORIES}/lib/x64/SDL2.lib)
target_link_libraries(main PRIVATE ${SDL2_DEVEL_DIRECTORIES}/lib/x64/SDL2main.lib)
target_link_libraries(main PRIVATE ${SDL2_TTF_DIRECTORIES}/lib/x64/SDL2_ttf.lib)
set(LIB_SOURCES
	visitor_lib
	strategy_lib
	state_lib
	prototype_lib
	observer_lib
	mediator_lib
	iterator_lib
	interpretor_lib
	flyweight_lib
	factory_lib
	facade_lib
	decorator_lib
	chain_lib
	builder_lib
	abstract_lib
	adapter_lib
	command_lib
	fluent_lib
	objectpool
	nlohmann_json::nlohmann_json
	specification_lib
)
add_library(myout INTERFACE)
target_include_directories(myout INTERFACE "${CMAKE_SOURCE_DIR}/src/shared")
#For target to use  
target_include_directories(main PUBLIC ${SUBDIRECTORIES} ${SDL2_DEVEL_DIRECTORIES}/include ${SDL2_TTF_DIRECTORIES}/include)
target_link_directories(main PRIVATE  ${SDL2_DEVEL_DIRECTORIES}/lib/x64 ${SDL2_TTF_DIRECTORIES}/lib/x64)
target_link_libraries(main PRIVATE ${LIB_SOURCES})
#add_library(main STATIC ${LIB_SOURCES})

