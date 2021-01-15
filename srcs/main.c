#include <stdio.h>
#include "ft_printf.h"

int main() {
	printf("%*.*s\n", 100, 3, "23456");
	ft_printf("%*.*s\n", 100, 3, "23456");
	return 0;
}
