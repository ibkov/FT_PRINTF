#include "ft_print.h"

char *ft_find_precent(char *str)
{
    while (*str != '%' && *str)
	{
		ft_putchar_fd(*str, 1);
		str++;
	}
    if (*str == '%')
        return (str);
    return (NULL);
}

int ft_analisys_str(char *format)
{
    if (format)
    {
        if (++*format == 's')
            return (1);
    }
    return 0;
}


