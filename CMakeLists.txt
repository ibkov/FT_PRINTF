cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(srcs/ft_printf.c srcs/ft_parse_format.c srcs/ft_printf.h libft/ft_isdigit.c libft/ft_putstr_fd.c libft/libft.h libft/ft_putchar_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_putchar_fd.c)