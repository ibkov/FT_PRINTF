#include "ft_printf.h"
#include <stdio.h>

int ft_printString(va_list arg_ptr, t_flags list_flags, int *count)
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
		*count += addForwardChar(' ', list_flags.width - len);
		ft_putstr_fd(arg, 1);
	}
	else if (list_flags.width != 0 && list_flags.minus)
	{
		ft_putstr_fd(arg, 1);
		*count += addForwardChar(' ', list_flags.width - len);
	}
	else
		ft_putstr_fd(arg, 1);
	free(arg);
	return ((int)(*count + len));
}

