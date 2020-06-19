# Andrue Peters 
# 4/25/20
#
# Master level cmake file to build CUDD
#

cmake_minimum_required (VERSION 3.12.2)
project (x3)

# use C++17
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

# compile-time options and cxx standard
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)


find_package(Boost REQUIRED COMPONENTS )
add_executable(warmingup src/example1/warming_up.cpp )


add_executable(example2 src/example2/actions.cpp)
add_executable(example3 src/example3/complex.cpp)
add_executable(example4 src/example4/numlist_4.cpp)
add_executable(roman    src/roman_numerals/roman_numerals.cpp)
add_executable(employee src/employee/employee.cpp src/employee/main.cpp)
add_executable(annotation src/annotation/annotation.cpp)