#include "ft_printf.h"

int ft_printPrecent(t_flags list_flags)
{
    int len;
	char chr;

    len = 1;
	chr = ' ';
	if (list_flags.zero)
		chr = '0';
    if (list_flags.width != 0 && !list_flags.minus)
	{
		while (list_flags.width > len++)
			ft_putchar_fd(chr, 1);
		ft_putchar_fd('%', 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putchar_fd('%', 1);
		while (list_flags.width > len++)
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putchar_fd('%', 1);
    return (0);
}