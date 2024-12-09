cmake_minimum_required(VERSION 3.28)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        MySort.c
        MySort.h
        Macro.h
        LinkList.h
        ListList.c
        ArrOutput.h
        ArrOutput.c
)
