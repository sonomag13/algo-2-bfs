cmake_minimum_required(VERSION 3.15)
project(clone_graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(clone_graph main.cpp CloneGraph.cpp cmake-build-debug/DataStructure.h)