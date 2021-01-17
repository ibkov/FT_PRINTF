#include "ft_printf.h"

void printValue(va_list arg_ptr, t_flags list_flags, const char* format, int *i, int *count)
{
    if (format[*i] == 's')
        ft_printString(arg_ptr, list_flags, count);
    if (format[*i] == 'c')
        ft_printChar(arg_ptr, list_flags, count);
    if (format[*i] == '%')
        *count += ft_printPrecent(list_flags);
    if (format[*i] == 'd' || format[*i] == 'i')
        *count += ft_printInteger(arg_ptr, list_flags);
    if (format[*i] == 'u')
        *count += ft_printUnsignedInteger(arg_ptr, list_flags);
    if (format[*i] == 'p')
        *count += ft_printPointer(arg_ptr, list_flags);
    if (format[*i] == 'x')
        *count += ft_printHexadecimal(arg_ptr, list_flags, "0123456789abcdef");
    if (format[*i] == 'X')
        *count += ft_printHexadecimal(arg_ptr, list_flags, "0123456789ABCDEF");
    
}