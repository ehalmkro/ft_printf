cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "Libft/*.c")
add_library(ft STATIC ${SOURCES} Libft/ft_strndup.c)


add_library(ft_printf src/ft_printf.c src/handle_integer.c Libft/libft.h src/output.c)
add_executable(test src/ft_printf.c src/handle_integer.c Libft/libft.h src/output.c)

target_link_libraries(ft_printf ft)
target_link_libraries(test ft)

