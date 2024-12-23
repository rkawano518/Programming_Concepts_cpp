cmake_minimum_required(VERSION 3.31.2)
project(Programming_Concepts_cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(Programming_Concepts_cpp ${SOURCES})
target_include_directories(Programming_Concepts_cpp PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/RK_Logger/include)

add_subdirectory("${CMAKE_SOURCE_DIR}/RK_Logger")
target_link_libraries(Programming_Concepts_cpp PRIVATE rk_logger)
