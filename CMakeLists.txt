cmake_minimum_required(VERSION 3.17)
project(FT_PRINTF C)

set(CMAKE_C_STANDARD 99)

add_executable(FT_PRINTF main.c ft_print.h ft_printf.c libft/ft_itoa.c)