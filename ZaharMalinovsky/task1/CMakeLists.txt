cmake_minimum_required(VERSION 3.17)
project(task1 C)

set(CMAKE_C_STANDARD 90)

add_executable(task1 main.c TariffsBase.h TariffsBase.c functions.h functions.c)