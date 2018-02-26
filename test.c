#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <wchar.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	wchar_t wc = L'的';
	printf("%d\n", printf("%5C\n", wc));
	//的
}