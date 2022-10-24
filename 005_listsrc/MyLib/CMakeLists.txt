# Setting 
cmake_minimum_required(VERSION 3.10)
project(MyLib)

# Debug message 
# set(ABC "Hey")
# message("Hello World ${ABC}")
message("Hello World")

# Define Source 
#set(src_files src/MyLib.cpp include/MyLib.h)

file(GLOB_RECURSE search_src_files 
	"include/*.*"
	"src/*.*"
)
## message("search_src_files = ${search_src_files}")

foreach(FILE ${search_src_files}) 
	get_filename_component(PARENT_DIR "${FILE}" PATH)    
	file(RELATIVE_PATH PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} ${PARENT_DIR})
	string(REPLACE "/" "\\" GROUP "${PARENT_DIR}")
	set(GROUP "${GROUP}")
	source_group("${GROUP}" FILES "${FILE}")
endforeach()

add_library(MyLib ${search_src_files})

#set(src_files src/MathLib.cpp src/StringLib.cpp include/MyLib.h)
#add_library(MyLib ${src_files})

# Define the Target 
target_include_directories(MyLib PUBLIC include)
