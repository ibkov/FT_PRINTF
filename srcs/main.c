#include <stdio.h>
#include "ft_printf.h"

int main() {
	// printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284);
	// ft_printf("%i11.22, %10.d,", 8, -12);
	printf("|%d", ft_printf("%c", 'a'));

	// printf("   len_o = %d\n\n   ", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284));
	// printf("   len-my = %d\n\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, 4294967284, 4294967284, 4294967284));
	return 0;
}
