cmake_minimum_required(VERSION 3.28)
project(CPP_Codes)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Codes Linked_List.cpp ListNode.cpp ListNode.h
        DListNode.cpp
        DListNode.h
        Doubly_Linked_List.cpp)
