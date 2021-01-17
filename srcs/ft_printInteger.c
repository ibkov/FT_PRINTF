#include "ft_printf.h"

int	    addForwardChar(char c, int width)
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

int checkPrecision(t_flags list_flags, int num_int, int len)
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

int checkWidth(t_flags list_flags, int num_int, int len)
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
        count += addForwardChar('0', list_flags.width - len);
    }
    else if (list_flags.precision >= len)
    {
        if (num_int < 0)
            count += addForwardChar(' ', list_flags.width - list_flags.precision - 1);
        else
            count += addForwardChar(' ', list_flags.width - list_flags.precision);
    }
    else
        count += addForwardChar(' ', ft_abs(list_flags.width) - len);
    return (count);
}

int checkMinus(t_flags list_flags, int num_int, int len, char *arg)
{
    int count;

    count = 0;
    (num_int < 0) ? arg++ : arg;
    if (list_flags.minus || list_flags.width < 0)
    {
        count += checkPrecision(list_flags, num_int, len);
        count += ft_strlen(arg);
        ft_putstr_fd(arg, 1);
        count += checkWidth(list_flags, num_int, len);
    }
    else if (!list_flags.minus)
    {
        count += checkWidth(list_flags, num_int, len);
        count += checkPrecision(list_flags, num_int, len);
        count += ft_strlen(arg);
        ft_putstr_fd(arg, 1);
    }
    return (count);
}

int ft_printInteger(va_list arg_ptr, t_flags list_flags)
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
        return (count += addForwardChar(' ', list_flags.width));
    count += checkMinus(list_flags, num_int, len, arg);

    return (count);

}