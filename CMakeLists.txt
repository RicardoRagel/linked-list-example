cmake_minimum_required(VERSION 2.8.9)
project(linked_list)

#########
# BUILD
#########
include_directories(include)
add_executable(linked_list_example src/main.cpp src/LinkedList.cpp)