#include <stdio.h>
#include "ft_printf.h"

int main() {
	printf("%-.10d\n", -123456);
	ft_printf("%-.10d", -123456);

	// printf("%d\n", printf("%-.10d\n", -123456));
	// printf("%d", ft_printf("%-.10d\n", -123456));
	return 0;
}
