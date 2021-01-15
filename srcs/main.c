#include <stdio.h>
#include "ft_printf.h"

int main() {
	printf("abc%1h0.1s %.2s\n", "123", "12");
	ft_printf("abc%1h0.1s %.2s", "123", "12");
	return 0;
}
