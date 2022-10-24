# Read Me 

## Reference 
- https://code.visualstudio.com/docs/languages/cpp
- https://www.itread01.com/content/1549546383.html



## How to build 
1. First time
> cmake .   # Use cmake to create the Make files 
> make      # build the project 
> ./hello   # run the Hello World     

## Concept & Note 
1. Cmake is used generate the Makefile for my own platform 
2. It defines the main and the output 


## gitignore for 
https://github.com/github/gitignore/blob/master/CMake.gitignore
```
CMakeLists.txt.user
CMakeCache.txt
CMakeFiles
CMakeScripts
Testing
Makefile
cmake_install.cmake
install_manifest.txt
compile_commands.json
CTestTestfile.cmake
_deps
```

## trouble shooting 
```
  Add the installation prefix of "fmt" to CMAKE_PREFIX_PATH or set "fmt_DIR"
  to a directory containing one of the above files.  If "fmt" provides a
  separate development package or SDK, be sure it has been installed.
``` 
- Missed the Vcpkg setting the cmake command line

## Install Fmt 
https://fmt.dev/latest/index.html
https://fmt.dev/dev/usage.html