#include "ft_printf.h"
#include <locale.h>
int		main(void)
{
	//setlocale(LC_ALL, "");
	//ft_printf("%d", ft_printf("%S\n", L"Á±≥"));
	ft_printf("%ls\n", L"Á±≥");
	//printf("%S\n", L"Á±≥");

	return 0;
}
/*
2 - α
3 - 的
4 - 𐍈
*/
