cmake_minimum_required(VERSION 3.26)
project(Programmercarl)

set(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY(LinkedList)
ADD_SUBDIRECTORY(Array)
ADD_SUBDIRECTORY(HashTable)
ADD_SUBDIRECTORY(String)
ADD_SUBDIRECTORY(StackQueue)

add_executable(Programmercarl main.cpp)
