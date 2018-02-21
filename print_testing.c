#include <stdio.h>

int		main(void)
{
	printf("%'d\n", 10);
	printf("%5-d\n", 10);
	printf("%14.3ys%d\n", "Hello");
	return (0);
}