cmake_minimum_required(VERSION 3.27)
project(paraPilha C)

set(CMAKE_C_STANDARD 11)

add_executable(paraPilha main.c
        funcoes.h
        funcoes.c)
