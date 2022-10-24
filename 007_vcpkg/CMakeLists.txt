cmake_minimum_required(VERSION 3.10)

project(007_vcpkg)

# 1: Find the package 
find_package(fmt CONFIG REQUIRED)

add_subdirectory(MyLib)
#add_subdirectory(fmt)

add_executable(MyApp MyApp/main.cpp MyApp/pch.h)



target_precompile_headers(MyApp PRIVATE MyApp/pch.h)

target_link_libraries(MyApp PRIVATE MyLib)

# 2: Link the package
target_link_libraries(MyApp PRIVATE fmt::fmt)
#target_link_libraries(MyApp PRIVATE fmt::fmt-header-only)




# find_package(unofficial-sqlite3 CONFIG REQUIRED)

# add_executable(math main.cpp)

# target_link_libraries(math PRIVATE unofficial::sqlite3::sqlite3)



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
