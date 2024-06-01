cmake_minimum_required(VERSION 3.28)
project(Hash_functions)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hash_functions main.cpp
        separate_chaining.cpp
        separate_chaining.h
        open_addressing.cpp
        open_addressing.h
        cuckoo_hashing.cpp
        cuckoo_hashing.h)
