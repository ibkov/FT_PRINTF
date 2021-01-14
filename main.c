#include <stdio.h>
#include "ft_printf.h"

int main() {
	ft_printf("abc%-100sk   %s", "ooo", "yyuii");
	printf("\nabc%-100sk   %s", "ooo", "yyuii");
	return 0;
}
