# Clean up 

CMAKE_SCRIPT=/Users/kenlee/workspace/cpp/vcpkg/scripts/buildsystems/vcpkg.cmake 

#cmake -GXcode DCMAKE_POSITION_INDEPENDENT_CODE=TRUE -B ./xcode_prj/ -D CMAKE_TOOLCHAIN_FILE=$CMAKE_SCRIPT ./
cmake -GXcode -DBUILD_SHARED_LIBS=TRUE -B ./xcode_prj/ -D CMAKE_TOOLCHAIN_FILE=$CMAKE_SCRIPT ./

