# Clean up 

#cmake -B ./build/ ./


CMAKE_SCRIPT=/Users/kenlee/workspace/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake 

cmake -B ./build/ -D CMAKE_TOOLCHAIN_FILE=$CMAKE_SCRIPT ./
