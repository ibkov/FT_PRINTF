#include <stdio.h>
#include "ft_printf.h"

int main() {

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	// printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284);
	// ft_printf("%i11.22, %10.d,", 8, -12);
	// printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", -2, 0, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	// ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", -2, 0, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	// ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", 12, 18, c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	// printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", 12, 18, c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	printf("%-*c|\n", ls4, '-');
	ft_printf("%-*c|\n", 4, '-');
	
	// ft_printf("%% *.5i 42 == |% *.5i|", 4, 42);

// while (a < 5) //T34-69
// 	{
// 		PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("   len_o = %d\n\n   ", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284));
	// printf("   len-my = %d\n\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284));
	return 0;
}
