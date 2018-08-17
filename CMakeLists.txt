cmake_minimum_required(VERSION 3.10)
project(Heap)

set(CMAKE_CXX_STANDARD 11)

include_directories("C:/dev/boost/include" "include")

add_executable(main src/main.cpp src/HeapPerformanceTester.h src/HeapPerformanceTester.cpp include/Heap.hpp)

