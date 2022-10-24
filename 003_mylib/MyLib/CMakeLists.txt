# Setting 
cmake_minimum_required(VERSION 3.10)
project(MyLib)

# Debug message 
set(ABC "Hey")
message("Hello World ${ABC}")

# Define Source 
set(src_files src/MyLib.cpp include/MyLib.h)
add_library(MyLib ${src_files})

# Define the Target 
target_include_directories(MyLib PUBLIC include)
