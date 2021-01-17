#include "ft_printf.h"

int checkPrecisionHexadecimal(t_flags list_flags, int len)
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

int checkWidthHexadecimal(t_flags list_flags, int len)
{
    int count;

    count = 0;
    if (list_flags.zero && list_flags.precision < 1 && !list_flags.minus)
        count += addForwardChar('0', list_flags.width - len);
    else if (list_flags.precision >= len)
        count += addForwardChar(' ', list_flags.width - list_flags.precision);
    else
        count += addForwardChar(' ', list_flags.width - len);
    return (count);
}

int checkMinusHexadecimal(t_flags list_flags, int len, char *arg)
{
    int count;

    count = 0;
    if (list_flags.minus)
    {
        count += checkPrecisionHexadecimal(list_flags, len);
        count += len;
        ft_putstr_fd(arg, 1);
        count += checkWidthHexadecimal(list_flags, len);
    }
    else if (!list_flags.minus)
    {
        count += checkWidthHexadecimal(list_flags, len);
        count += checkPrecisionHexadecimal(list_flags, len);
        count += len;
        ft_putstr_fd(arg, 1);
    }
    return (count);
}

int ft_printHexadecimal(va_list arg_ptr, t_flags list_flags, char *alf_hex)
{
    char *arg;
    int count;
    unsigned int num;
    int len;

    count = 0;
    if (!(num = va_arg(arg_ptr, unsigned int)))
		arg = ft_strdup("0");
    else
        arg = ft_convert_base(alf_hex, num);
    len = ft_strlen(arg);
    if (*arg == '0' && list_flags.precision == 0)
        count += addForwardChar(' ', list_flags.width);
    else
        count += checkMinusHexadecimal(list_flags, len, arg);
    free(arg);
    return (count);
}