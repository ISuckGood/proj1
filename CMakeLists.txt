cmake_minimum_required(VERSION 3.0.0)
# add a c++ 14 standard
set(CMAKE_CXX_STANDARD 14)
project(testcmake VERSION 0.1.0)
add_executable(testcmake main.cpp)
target_link_libraries(testcmake pthread)

