#include "ft_printf.h"

void ft_printChar(va_list arg_ptr, t_flags list_flags, int *count)
{
    int arg;

    arg = va_arg(arg_ptr, int);
    if (list_flags.width != 0 && !list_flags.minus)
	{
		*count += addForwardChar(' ', list_flags.width - 1);
		ft_putchar_fd(arg, 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putchar_fd(arg, 1);
		*count += addForwardChar(' ', list_flags.width - 1);
	}
	else
	{
		ft_putchar_fd(arg, 1);
		*count += 1;
	}
}