cmake_minimum_required(VERSION 3.2)

project(poc-glfw CXX)

add_executable(a.out main.cpp)

find_package(glfw3 3.3 REQUIRED)

target_link_libraries(a.out PUBLIC glfw)
target_link_libraries(a.out PUBLIC GLESv2)

