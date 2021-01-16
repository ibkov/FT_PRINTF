#include "ft_printf.h"

int ft_printPrecent(t_flags list_flags)
{
    int len;
	char chr;
	int count;

    len = 1;
	count = 1;
	chr = ' ';
	if (list_flags.zero)
		chr = '0';
    if (list_flags.width != 0 && !list_flags.minus)
	{
		count += addForwardChar(chr, list_flags.width - len);
		ft_putchar_fd('%', 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putchar_fd('%', 1);
		count += addForwardChar(' ', list_flags.width - len);
	}
	else
		ft_putchar_fd('%', 1);
    return (count);
}