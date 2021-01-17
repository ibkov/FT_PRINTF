#include "ft_printf.h"

int check_precision_hexadecimal(t_flags list_flags, int len)
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

int check_width_hexadecimal(t_flags list_flags, int len)
{
    int count;

    count = 0;
    if (list_flags.zero && list_flags.precision < 0 && !list_flags.minus)
        count += add_forward_char('0', list_flags.width - len);
    else if (list_flags.precision >= len)
        count += add_forward_char(' ', list_flags.width - list_flags.precision);
    else
        count += add_forward_char(' ', list_flags.width - len);
    return (count);
}

int check_minus_hexadecimal(t_flags list_flags, int len, char *arg)
{
    int count;

    count = 0;
    if (list_flags.minus)
    {
        count += check_precision_hexadecimal(list_flags, len);
        count += ft_putstr_fd(arg, 1);
        count += check_width_hexadecimal(list_flags, len);
    }
    else if (!list_flags.minus)
    {
        count += check_width_hexadecimal(list_flags, len);
        count += check_precision_hexadecimal(list_flags, len);
        count += ft_putstr_fd(arg, 1);
    }
    return (count);
}

int ft_print_hexadecimal(va_list arg_ptr, t_flags list_flags, char *alf_hex)
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
        count += add_forward_char(' ', ft_abs(list_flags.width));
    else
        count += check_minus_hexadecimal(list_flags, len, arg);
    free(arg);
    return (count);
}