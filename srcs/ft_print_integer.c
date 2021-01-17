#include "ft_printf.h"

int	    add_forward_char(char c, int width)
{
	int i;

	i = 0;
	while (i < width)
    {
        ft_putchar_fd(c, 1);
        i++;
    }
	return (i);
}

int check_precision(t_flags list_flags, int num_int, int len)
{
    int count;
    int i;

    count = 0;
    i = 0;
    if (num_int < 0 && list_flags.precision < len && !list_flags.zero)
    {
        ft_putchar_fd('-', 1);
        count++;
    }
    else if (list_flags.precision > 0)
    {
        if (num_int < 0 && --i == -1)
        {
            ft_putchar_fd('-', 1);
            count++;
        }
        while (i++ < list_flags.precision - len)
        {
            ft_putchar_fd('0', 1);
            count++;
        }
    }
    return (count);
}

int check_width(t_flags list_flags, int num_int, int len)
{
    int count;

    count = 0;
    if (list_flags.zero)
    {
        if (num_int < 0)
        {
            ft_putchar_fd('-', 1);
            count++;
        }
        count += add_forward_char('0', list_flags.width - len);
    }
    else if (list_flags.precision >= len)
    {
        if (num_int < 0)
            count += add_forward_char(' ', list_flags.width - list_flags.precision - 1);
        else
            count += add_forward_char(' ', list_flags.width - list_flags.precision);
    }
    else
        count += add_forward_char(' ', list_flags.width - len);
    return (count);
}

int check_minus(t_flags list_flags, int num_int, int len, char *arg)
{
    int count;

    count = 0;
    (num_int < 0) ? arg++ : arg;
    if (list_flags.minus || (list_flags.width < 0 && num_int > 0))
    {
        count += check_precision(list_flags, num_int, len);
        count += ft_putstr_fd(arg, 1);
        count += check_width(list_flags, num_int, len);
        if (list_flags.width <= 0 && ft_abs(list_flags.width) >= len)
        {
            count += add_forward_char(' ', ft_abs(list_flags.width) - ((list_flags.precision > len) ? list_flags.precision : len));
        }
    }
    else if (!list_flags.minus)
    {
        count += check_width(list_flags, num_int, len);
        count += check_precision(list_flags, num_int, len);
        count += ft_putstr_fd(arg, 1);
        if (num_int <= 0 && list_flags.width <= 0)
            count += add_forward_char(' ', ft_abs(list_flags.width) - ((list_flags.precision > len) ? list_flags.precision + 1 : len));
    }
    return (count);
}

int ft_print_integer(va_list arg_ptr, t_flags list_flags)
{
    int		num_int;
	char	*arg;
	int		len;
    int     count;

    count = 0;
	num_int = va_arg(arg_ptr, int);
	arg = ft_itoa(num_int);
	len = ft_strlen(arg);
    if ((list_flags.minus || list_flags.precision >= 0) && list_flags.zero)
		list_flags.zero = 0;
    if (list_flags.precision == 0 && *arg == '0')
        return (count += add_forward_char(' ', ft_abs(list_flags.width)));
    count += check_minus(list_flags, num_int, len, arg);

    return (count);

}