cmake_minimum_required(VERSION 3.31)
project(Queue_tail)

set(CMAKE_CXX_STANDARD 20)

add_executable(Queue_tail main.cpp
        MyQueue.cpp
        MyQueue.h
        Numbers.cpp
        Numbers.h)
