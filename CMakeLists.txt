cmake_minimum_required(VERSION 3.22)
project(SBExercise3151)

set(CMAKE_CXX_STANDARD 14)

add_executable(SBExercise3151 src/main.cpp include/SharedToys.h src/SharedToys.cpp)

target_include_directories(SBExercise3151 PUBLIC include)