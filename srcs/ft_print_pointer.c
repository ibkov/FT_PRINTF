#include "ft_printf.h"

int     count_in_num_hex(unsigned long long num, int len)
{
	int i;

	i = 0;
	while (num > 0)
	{
		num /= len;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *alf_hex, unsigned long long num)
{
    char	*str;
	int		count_num;
    int     len;
	
    len = ft_strlen(alf_hex);
	count_num = count_in_num_hex(num, len);
	if (!(str = (char *)malloc(sizeof(char) * (count_num + 1))))
		return (NULL);
	str[count_num] = '\0';
	while (--count_num)
	{
		str[count_num] = alf_hex[num % len];
		num /= len;
	}
	if (count_num == 0)
		str[count_num] = alf_hex[num % len];
	return (str);

}

int check_minus_pointer(t_flags list_flags, int len, char *arg)
{
    int count;

    count = 0;
    if (list_flags.minus)
    {
        count += ft_putstr_fd("0x", 1);
        count += ft_putstr_fd(arg, 1);
        count += add_forward_char(' ', list_flags.width - (len + 2));
    }
    else if (!list_flags.minus)
    {
        count += add_forward_char(' ', list_flags.width - (len + 2));
        count += ft_putstr_fd("0x", 1);
        count += ft_putstr_fd(arg, 1);
    }
    return (count);
}


int ft_print_pointer(va_list arg_ptr, t_flags list_flags)
{
    char *arg;
    int count;
    unsigned long long num;
    int len;

    count = 0;
    num = va_arg(arg_ptr, unsigned long long);
    if (!num)
		arg = (list_flags.precision == 0) ? ft_strdup("") : ft_strdup("0");
    else
        arg = ft_convert_base("0123456789abcdef", num);
    len = ft_strlen(arg);
    count += check_minus_pointer(list_flags, len, arg);
    free(arg);
    return (count);
}