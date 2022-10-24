cmake_minimum_required(VERSION 3.10)

project(005_listrc)

add_subdirectory(MyLib)

add_executable(MyApp MyApp/main.cpp MyApp/pch.h)

target_precompile_headers(MyApp PRIVATE MyApp/pch.h)
target_link_libraries(MyApp MyLib)




# Basic Setting 
# cmake_minimum_required (VERSION 2.8)
# project (003_mylib)

# # Define the Directories 
# add_subdirectory(MyLib)     # using relative path 

# # Define the executable 
# add_executable(MyApp MyApp/main.cpp MyApp/pch.h)    

# # Linking 
# target_precompile_headers(MyApp PRIVATE MyApp/pch.h) # What's precompile header?
# target_link_libraries(MyApp MyLib)
