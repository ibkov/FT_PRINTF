#include "ft_printf.h"

int ft_printChar(va_list arg_ptr, t_flags list_flags)
{
    int arg;

    arg = va_arg(arg_ptr, int);
    printf("%c", arg);
    printf("%d", list_flags.width);
    return (0);
}