#include "ft_printf.h"
#include <locale.h>
int		main(void)
{
	long long int x = -45;

	ft_printf("%d\n", 0);
	ft_printf("5 - %012.3d\n\n", x);
	return (0);
}
/*
2 - α
3 - 的
4 - 𐍈
*/
