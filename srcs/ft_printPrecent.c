#include "ft_printf.h"

int ft_printString(va_list arg_ptr, t_flags list_flags)
{
    int arg;
    int len;

    len = 1;
    arg = va_arg(arg_ptr, int);
    if (list_flags.width != 0 && !list_flags.minus)
	{
		while (list_flags.width > len++)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(arg, 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putchar_fd(arg, 1);
		while (list_flags.width > len++)
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putchar_fd(arg, 1);
    return (0);
}