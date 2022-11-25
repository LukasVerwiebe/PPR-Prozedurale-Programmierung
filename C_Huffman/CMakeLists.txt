cmake_minimum_required(VERSION 3.23)
project(C_Huffman C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Huffman main.c huffman_common.h io.c huffman.c)
