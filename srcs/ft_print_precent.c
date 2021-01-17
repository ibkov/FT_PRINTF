#include "ft_printf.h"

int ft_print_precent(t_flags list_flags)
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
		count += add_forward_char(chr, list_flags.width - len);
		ft_putchar_fd('%', 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putchar_fd('%', 1);
		count += add_forward_char(' ', list_flags.width - len);
	}
	else
		ft_putchar_fd('%', 1);
    return (count);
}