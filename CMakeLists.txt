cmake_minimum_required(VERSION 3.29)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

# Include headers
set(HEADERS
        LinkedList/list.h
        LinkedList/listnode.h
)


# Source files
set(SOURCES
        main.c
        LinkedList/list.c
        LinkedList/listnode.c
)

add_executable(DataStructures ${SOURCES})
