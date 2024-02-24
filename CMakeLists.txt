cmake_minimum_required(VERSION 3.27)
project(hanoi)

set(CMAKE_CXX_STANDARD 17)

add_executable(hanoi main.cpp
        Stack.h
        Node.h
        StackHanoi.cpp
        StackHanoi.h
        Util.cpp
        Util.h
        Hanoi.cpp
        Hanoi.h)
