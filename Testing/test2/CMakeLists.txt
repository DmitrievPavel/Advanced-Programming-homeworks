
cmake_minimum_required (VERSION 3.8)
add_subdirectory(/Users/Павел/Desktop/Homeworks/Advansed/test/Catch2 Catch2-build)
add_executable(Test2 test1.cpp)
target_link_libraries(Test2 PRIVATE Catch2::Catch2WithMain)
