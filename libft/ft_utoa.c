#include "libft.h"

int     countInNumUtoa(long num)
{
	int     i;
	
	i = 1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char			*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = countInNumUtoa(num);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
    len--;
	str[len] = '\0';
	while (num / 10 >= 1)
	{
		str[--len] = (num % 10) + 48;
		num /= 10;
	}
	str[0] = (num % 10) + 48;
	return (str);
}