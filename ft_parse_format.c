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

char ft_parse_modif(char *modif)
{
    char    *temp;
    char    *begin;
    char    *end;
    int     len_modif;

    if (modif)
    {
        temp = modif;
        if (end = ft_strchr(modif, 's'))
        {
            end = '\0';
        }
        printf("%s",  modif);
        len_modif = ft_strlen(modif);
        printf("%d", len_modif);
    }
    return 0;
}


