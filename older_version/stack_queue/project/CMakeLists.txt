cmake_minimum_required(VERSION 3.23)
project(clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(clion main.cpp my_stack.hpp my_queue.hpp expression_function.h expression_conversion.cpp expression_calculation.cpp)
