cmake_minimum_required(VERSION 3.5)
project(CPP_python)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#python Ŀ¼
INCLUDE_DIRECTORIES(C:/Users/Administrator/AppData/Local/Programs/Python/Python39/include)
LINK_DIRECTORIES(C:/Users/Administrator/AppData/Local/Programs/Python/Python39/libs)
LINK_LIBRARIES(python39_d.lib)
add_executable(CPP_python2
cpp_python2.cpp)
#target_link_libraries(CPP_python2 python39_d.dll)
