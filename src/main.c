#include "ft_printf.h"

int		main(void)
{
	//ft_printf("Check,%% %da\n%ca\n%sa\n", 15, 'A', "Hell");
	int i = ft_printf("%05ca\n%c\n", 'A', 'B');
	printf("%d\n", i);
	return 1;
}
