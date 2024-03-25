cmake_minimum_required(VERSION 3.28)
project(DLL)

set(CMAKE_CXX_STANDARD 17)

add_executable(DLL main.cpp
        DLinkedList.cpp
        DLinkedList.h)
