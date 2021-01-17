#include "ft_printf.h"

int checkPrecisionUnsigned(t_flags list_flags, int len)
{
    int i;

    i = 0;
    if (list_flags.precision > 0)
    {
        while (i < list_flags.precision - len)
        {
            ft_putchar_fd('0', 1);
            i++;
        }
        return (i);
    }
    return (0);
}

int checkWidthUnsigned(t_flags list_flags, int len)
{
    int count;

    count = 0;
    if (list_flags.zero && list_flags.precision < 0 && !list_flags.minus)
        count += addForwardChar('0', list_flags.width - len);
    else if (list_flags.precision >= len)
        count += addForwardChar(' ', list_flags.width - list_flags.precision);
    else
        count += addForwardChar(' ', list_flags.width - len);
    return (count);
}

int checkMinusUnsigned(t_flags list_flags, int len, char *arg)
{
    int count;

    count = 0;
    if (list_flags.minus)
    {
        count += checkPrecisionUnsigned(list_flags, len);
        count += len;
        ft_putstr_fd(arg, 1);
        count += checkWidthUnsigned(list_flags, len);
    }
    else if (!list_flags.minus)
    {
        count += checkWidthUnsigned(list_flags, len);
        count += checkPrecisionUnsigned(list_flags, len);
        count += len;
        ft_putstr_fd(arg, 1);
    }
    return (count);
}

int ft_printUnsignedInteger(va_list arg_ptr, t_flags list_flags)
{
    char	*arg;
	int		len;
	int		count;

    count = 0;
	arg = ft_utoa(va_arg(arg_ptr, unsigned int));
    len = ft_strlen(arg);
    if (*arg == '0' && list_flags.precision == 0)
        count += addForwardChar(' ', ft_abs(list_flags.width));
    else
        count += checkMinusUnsigned(list_flags, len, arg);
    free(arg);
    return (count);
}