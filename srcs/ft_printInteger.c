#include "ft_printf.h"

// int ft_printInteger(va_list arg_ptr, t_flags list_flags)
// {
// 	int     len;
//     char    *arg;
//     char    chr;
//     int     neg;

//     chr = ' ';
//     neg = 0;
//     if (!(arg = ft_strdup(ft_itoa(va_arg(arg_ptr, int)))))
// 		arg = ft_strdup("(null)");
//     if (list_flags.zero)
// 		chr = '0';
//     if (arg[0] == '-')
//     {
//         neg = 1;
//         arg = ft_strdup(arg + 1);
//     }
// 	len = ft_strlen(arg);
//     if (list_flags.width && list_flags.precision != -1 && !list_flags.zero)
//     {
//         while (list_flags.width > len)
//         {
//             if (list_flags.width - list_flags.precision == 1 && neg)
//                 ft_putchar_fd('-', 1);
//             else if (list_flags.width > list_flags.precision)
//                 ft_putchar_fd(' ', 1);
//             else if (list_flags.precision > len)
//                 ft_putchar_fd('0', 1);
//             list_flags.width--;
//         }
//         ft_putstr_fd(arg, 1);
//     }
// 	else if (list_flags.width != 0 && !list_flags.minus && !neg)
// 	{
// 		while (list_flags.width > len++)
// 			ft_putchar_fd(chr, 1);
// 		ft_putstr_fd(arg, 1);
// 	}
// 	else if (list_flags.width != 0 && list_flags.minus && !neg)
// 	{
// 		ft_putstr_fd(arg, 1);
// 		while (list_flags.width > len++)
// 			ft_putchar_fd(chr, 1);
// 	}
//     else if (list_flags.width != 0 && !list_flags.minus && neg)
//     {
//         ft_putchar_fd('-', 1);
//         len++;
//         while (list_flags.width > len++)
// 			ft_putchar_fd(chr, 1);
// 		ft_putstr_fd(arg, 1);
// 	}
// 	else
//     {
//         (neg) ? ft_putchar_fd('-', 1) : 0;
//         while (list_flags.precision > len++)
//             ft_putchar_fd('0', 1);
// 		ft_putstr_fd(arg, 1);
//     }
// 	free(arg);
// 	return (0);
// }

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

    count = 1;
    i = 0;
    if (num_int < 0 && list_flags.precision < len && !list_flags.zero)
        ft_putchar_fd('-', 1);
    else if (list_flags.precision > 0)
    {
        count = 0;
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
        count += addForwardChar(' ', list_flags.width - len);
    return (count);
}

int checkMinus(t_flags list_flags, int num_int, int len, char *arg)
{
    int count;

    count = 0;
    (num_int < 0) ? arg++ : arg;
    if (list_flags.minus)
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