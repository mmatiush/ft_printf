#include "ft_printf.h"
#include <locale.h>
int		main(void)
{
	unsigned x = -45;
	// int ret1 = 0;
	// int ret2 = 0;

	// #define macro "%D, %D\n", 0, 0
	// ret1 = ft_printf(macro);
	// ret2 = printf(macro);

	// printf("r1 = %d, r2 = %d\n", ret1, ret2);

	ft_printf("%14u\n", x);
	ft_printf("%014u\n", x);
	ft_printf("%#14u\n", x);
	ft_printf("%#014u\n", x);
	ft_printf("%-14u\n", x);
	ft_printf("%-#14u\n", x);
	ft_printf("%14.4u\n", x);
	ft_printf("%-14.4u\n", x);

	return (0);
}
/*
2 - α
3 - 的
4 - 𐍈
*/
