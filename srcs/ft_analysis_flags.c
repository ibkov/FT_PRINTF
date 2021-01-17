#include "ft_printf.h"

void    init_flags(t_flags *list_flags)
{
	list_flags->minus = 0;
	list_flags->precision = -1;
	list_flags->zero = 0;
	list_flags->width = 0;

}

int		is_flag_char(char flagChar)
{
	return (flagChar == '-' || ft_isdigit(flagChar) || flagChar == '.' || flagChar == '*');
}

int     count_in_num(int num)
{
	int i;

	i = 0;
	if (!num)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void    processing_asterisk(t_flags *list_flags, va_list arg_ptr)
{
	if (!list_flags->precision)
		list_flags->precision = va_arg(arg_ptr, int);
	else if (list_flags->width < 1)
		list_flags->width = va_arg(arg_ptr, int);
	
}

void    analysis_flags(const char* format, int *i, t_flags *list_flags, va_list arg_ptr)
{
	while (format[*i] && is_flag_char(format[*i]))
	{
		if (format[*i] == '-')
			list_flags->minus = 1;
		if (format[*i] == '0' && list_flags->width == 0)
			list_flags->zero = 1;
		if (ft_isdigit(format[*i]) && list_flags->precision == -1 && format[*i] != '0')
		{
			list_flags->width = ft_atoi(&format[*i]);
			*i += count_in_num(list_flags->width) - 1;
		}
		if (format[*i] == '.') {
			list_flags->precision = 0;
		}
		if (ft_isdigit(format[*i]) && list_flags->precision != -1)
		{
			list_flags->precision = ft_atoi(&format[*i]);
			*i += count_in_num(list_flags->precision) - 1;
		}
		if (format[*i] == '*')
			processing_asterisk(list_flags, arg_ptr);
		(*i)++;
	}
}