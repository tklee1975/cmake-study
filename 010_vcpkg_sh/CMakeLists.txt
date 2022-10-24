cmake_minimum_required(VERSION 3.16)


set(CMAKE_TOOLCHAIN_FILE "./externals/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_CXX_STANDARD 17)
project(010_vcpkg)

# 1: Find the package 
find_package(fmt CONFIG REQUIRED)

add_executable(testApp main.cpp)
target_link_libraries(testApp PRIVATE fmt::fmt)
