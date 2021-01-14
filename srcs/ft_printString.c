#include "ft_printf.h"
#include <stdio.h>

int ft_printString(va_list arg_ptr, t_flags list_flags)
{
	char* arg;
	int len;

	len = 0;
	if (list_flags.type == 1)
	{
		arg = va_arg(arg_ptr, char*);
		if (list_flags.precision < (int)ft_strlen(arg) && list_flags.precision != -1)
		{
			printf("pres = %d \n len = %d\n", list_flags.precision, (int)ft_strlen(arg));
//			arg[list_flags.precision] = '\0';
		}
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
	}
	return (0);
}

