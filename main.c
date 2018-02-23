#include "ft_printf.h"

int		main(void)
{
	//ft_printf("Check,%% %da\n%ca\n%sa\n", 15, 'A', "Hell");
	ft_printf("%05ca\n%-35c\n", 'A', 'B');
	return 1;
}
