cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_library(ft_printf src/ft_printf.c include/ft_printf.h src/ft_strndup.c)
add_executable(test src/ft_printf.c src/ft_putstr.c src/ft_strlen.c src/ft_strndup.c)