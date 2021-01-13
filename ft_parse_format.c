#include "ft_printf.h"

int searchBeginSpecificator(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '%' && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
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

//int searchBeginSpecificator(va_list arg_ptr, char format)
//{
//	int     i;
//
//	if (format == '%')
//		i = 0;
//	else
//		ft_putchar_fd(format, 1);
//	return i;
//}


