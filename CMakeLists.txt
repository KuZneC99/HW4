cmake_minimum_required(VERSION 3.10)

project(HW4)

option(USE_STATIC "Use static library" ON)

add_executable(HW4 HW4.c)

add_library(arr_handling
STATIC
    libs/arr_handler.h
    libs/arr_gen.c
    libs/sort.c
    libs/single_array.c
    libs/benchmark.c
)

target_link_libraries(HW4 arr_handling)