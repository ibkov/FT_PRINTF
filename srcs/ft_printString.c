#include "ft_printf.h"
#include <stdio.h>

int ft_printString(va_list arg_ptr, t_flags list_flags)
{
	char* arg;
	int len;

	len = 0;
	if (!(arg = ft_strdup(va_arg(arg_ptr, char*))))
		arg = ft_strdup("(null)");
	if (list_flags.precision < (int)ft_strlen(arg) && list_flags.precision != -1)
		arg[list_flags.precision] = '\0';
	len = ft_strlen(arg);
	if (list_flags.width != 0 && !list_flags.minus)
	{
		while (list_flags.width > len++)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(arg, 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putstr_fd(arg, 1);
		while (list_flags.width > len++)
			ft_putchar_fd(' ', 1);
	}
	else
		ft_putstr_fd(arg, 1);
	free(arg);
	return (0);
}

