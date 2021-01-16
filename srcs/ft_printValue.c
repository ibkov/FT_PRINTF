#include "ft_printf.h"

void printValue(va_list arg_ptr, t_flags list_flags, const char* format, int *i, int *count)
{
    if (format[*i] == 's')
        *count = ft_printString(arg_ptr, list_flags);
    if (format[*i] == 'c')
        *count = ft_printChar(arg_ptr, list_flags);
    if (format[*i] == '%')
        *count = ft_printPrecent(list_flags);
    if (format[*i] == 'd' || format[*i] == 'i')
        *count = ft_printInteger(arg_ptr, list_flags);
        
    
}