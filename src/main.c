#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	// printf("0 - %o", 0);
	// printf("\n");
	// ft_printf("0 - %o", 0);
	// printf("\n");
	// printf("1 - %#o", 0);
	// printf("\n");
	// ft_printf("1 - %#o", 0);
	// printf("\n");
	// printf("2 - %#.O", 0);
	// printf("\n");
	// ft_printf("2 - %#.O", 0);
	// printf("\n");
	// printf("3 - %#.O", 0);
	// printf("\n");
	// ft_printf("3 - %#.O", 0);
	// printf("\n");
	// printf("4 - %#.o %#.0o", 0, 0);
	// printf("\n");
	// ft_printf("4 - %#.o %#.0o", 0, 0);
	// printf("\n");
	// printf("1 - %#.3o", 1);
	// printf("\n");
	// ft_printf("1 - %#.3o", 1);
	// printf("\n");
	// printf("2 - %#o", 0);
	// printf("\n");
	// ft_printf("2 - %#o", 0);
	// printf("\n");
	// printf("3 - %#.o, %#.0o", 0, 0);
	// printf("\n");
	// ft_printf("3 - %#.o, %#.0o", 0, 0);
	// printf("\n");
	// printf("4 - %#.o %#.0o", 0, 0);
	// printf("\n");
	// ft_printf("4 - %#.o %#.0o", 0, 0);
	// printf("\n");
	// printf("5 - %#.3o %#.3o", 0, 0);
	// printf("\n");
	// ft_printf("5 - %#.3o %#.3o", 0, 0);
	// printf("\n");
	// printf("6 - %#.o", 42);
	// printf("\n");
	// ft_printf("6 - %#.o", 42);
	// printf("\n");
	// printf("7 - %.o, %.0o", 0, 0);
	// printf("\n");
	// ft_printf("7 - %.o, %.0o", 0, 0);
	// printf("\n");
	// printf("8 - %5.o %5.0o", 0, 0);
	// printf("\n");
	// ft_printf("8 - %5.o %5.0o", 0, 0);
	// printf("\n");
	printf("{%*d}", -5, 42);
	printf("\n");
	ft_printf("{%*d}", -5, 42);
	printf("\n");
	printf("{%05.*d}", -6, 42);
	printf("\n");
	ft_printf("{%05.*d}", -6, 42);

}
/*
2 - α
3 - 的
4 - 𐍈
*/
