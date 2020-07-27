cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "Libft/*.c")
add_library(ft STATIC ${SOURCES} Libft/ft_strndup.c Libft/ft_itoa_base.c Libft/ft_ftoa.c Libft/ft_modf.c Libft/ft_putnstr.c Libft/ft_strupr.c Libft/ft_round.c Libft/ft_powl.c Libft/ft_uintmaxtoa.c)


add_library(ft_printf src/ft_printf.c src/get_spec.c src/handle_integer.c Libft/libft.h src/output.c src/handle_params.c src/handle_hex.c src/handle_string.c src/handle_char.c src/handle_float.c src/handle_pointer.c)
add_executable(test src/ft_printf.c src/get_spec.c src/handle_integer.c Libft/libft.h src/output.c src/handle_params.c main.c src/handle_hex.c src/handle_string.c src/handle_char.c src/handle_float.c src/handle_pointer.c)

target_link_libraries(ft_printf ft)
target_link_libraries(test ft)

