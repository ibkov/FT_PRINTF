#include "ft_printf.h"

void    init_flags(t_flags *list_flags)
{
	list_flags->minus = 0;
	list_flags->lenght = 0;
	list_flags->precision = -1;
	list_flags->type = 0;
	list_flags->width = 0;
}

int		checkFlag(char flag)
{
	return (flag == '-' || ft_isdigit(flag) || flag == '.' || flag == '*');
}

int     countInNum(int num)
{
	int     i;
	if (!num)
		return (1);
	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void    processingAsterisk(t_flags *list_flags, va_list arg_ptr)
{
	if (!list_flags->precision)
		list_flags->precision = va_arg(arg_ptr, int);
	else if (list_flags->width < 1)
		list_flags->width = va_arg(arg_ptr, int);
	
}

void    analysisFlags(const char* format, int *i, t_flags *list_flags, va_list arg_ptr)
{
	while (format[*i] && checkFlag(format[*i]))
	{
		if (format[*i] == '-')
			list_flags->minus = 1;
		if (ft_isdigit(format[*i]) && list_flags->precision == -1)
		{
			list_flags->width = ft_atoi(&format[*i]);
			*i += countInNum(list_flags->width);
		}
		if (format[*i] == '.') {
			list_flags->precision = 0;
		}
		if (ft_isdigit(format[*i]) && list_flags->precision != -1)
		{
			list_flags->precision = ft_atoi(&format[*i]);
			*i += countInNum(list_flags->precision) - 1;
		}
		if (format[*i] == '*')
			processingAsterisk(list_flags, arg_ptr);
		(*i)++;
	}
}