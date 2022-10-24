cmake_minimum_required(VERSION 3.10)

project(007_vcpkg)

set(CMAKE_CXX_STANDARD 17)

# 1: Find the package 
find_package(fmt CONFIG REQUIRED)
#find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


# SDL library
find_library(SDL SDL2 PATHS "${CMAKE_SOURCE_DIR}/lib")

# add_library("glad" "./glad/src/glad.c")
# include_directories("./glad/include")


add_executable(MyApp MyApp/main.cpp MyApp/pch.h)

target_precompile_headers(MyApp PRIVATE MyApp/pch.h)

# 2: Link the package
target_link_libraries(MyApp PRIVATE fmt::fmt)
#target_link_libraries(MyApp OpenGL)
target_link_libraries(MyApp PRIVATE imgui::imgui)
#target_link_libraries(MyApp "glad")
