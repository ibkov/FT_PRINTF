#include "ft_printf.h"

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

char *ft_parse_modif(char *modif)
{
    char    *temp;
    int     i;
    char    *end;
    int     len_modif;

    i = 0;
	while (modif[i] != 's' || modif[i] != '\0')
		i++;
	modif[i] = '\0';
	if (modif[i] == '\0')
		return (0);
	else
		return (modif);
}


