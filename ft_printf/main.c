#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len = ft_printf("%10.*i%*.10i", 7, 42, 8, -42);
	printf("%d\n", len);
	int res = printf("%10.*i%*.10i", 7, 42, 8, -42);
	printf("%d\n", res);

	return (0);
}
