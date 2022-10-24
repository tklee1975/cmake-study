cmake_minimum_required(VERSION 3.10)

project(011_testcpp)

set(CMAKE_CXX_STANDARD 17)

set(TEST_BIN_NAME      "test")
set(TEST_PATH          "./")
set(SRC_PATH	 	    "./src/")



# 1: Find the package 
# ------------------------------
#find_package(fmt CONFIG REQUIRED)


# 2: Define Source 
# ------------------------------
add_executable( ${TEST_BIN_NAME} ${TEST_PATH}/TestMain.cpp)

# 3: Link the package
# ------------------------------
#target_link_libraries(MyApp PRIVATE fmt::fmt)
#target_link_libraries(MyApp PRIVATE fmt::fmt-header-only)


# 4: Test Base 
set(TEST_NAME		"aTest")
add_executable(${TEST_NAME} ${SRC_PATH}/SimpleTest.cpp)             

# 5: Testing for Cpp Language 
set(TEST_NAME		"cppTest")
add_executable(${TEST_NAME} ${SRC_PATH}/CppTest.cpp)             
