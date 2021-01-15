#include "ft_printf.h"

void printValue(va_list arg_ptr, t_flags list_flags, const char* format, int *i)
{
    if (format[*i] == 's')
        ft_printString(arg_ptr, list_flags);
}