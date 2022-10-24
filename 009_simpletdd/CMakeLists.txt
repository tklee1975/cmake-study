cmake_minimum_required(VERSION 3.10)

project(009_simpletdd)

set(CMAKE_CXX_STANDARD 17)

set(TEST_BIN_NAME      "test")
set(TEST_PATH          "./")



# 1: Find the package 
# ------------------------------
#find_package(fmt CONFIG REQUIRED)


# 2: Define Source 
# ------------------------------
add_executable(
                ${TEST_BIN_NAME}
                ${TEST_PATH}/TestMain.cpp                
            )

# 3: Link the package
# ------------------------------
#target_link_libraries(MyApp PRIVATE fmt::fmt)
#target_link_libraries(MyApp PRIVATE fmt::fmt-header-only)


