#include <stdio.h>
#include <stdlib.h>

/*
char	*ft_lutoa_base(size_t value, int base, char c)
{
	char	*s;
	size_t 	n;
	int		i;

	n = value;
	i = 1;
	while ((value /= base) > 0)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
		n /= base;
	}
	return (s);
}
*/

int		main(void)
{
	int	a = 10;
	int b = 5;
	int c = 1;

	a += b + c;

	printf("%d\n", a);
}
/*
	int x = -45;
	int y = 45;

	printf("1 - %012d\n", x);
	printf("2 - %010d\n", x);
	printf("3 - %12d\n", x);
	printf("4 - %+12d\n", x);
	printf("5 - %+012d\n", x);
	printf("6 - %0+12d\n", x);
	printf("7 - %-12d\n", x);
	printf("8 - %- 12d\n", x);
	printf("9 - %-+12d\n", x);
	printf("1 - %12.4d\n", x);
	printf("2 - %-12.0d\n", x);
	printf("3 - %-12.2d\n", x);
	printf("4 - %-12.4d\n", x);
	printf("5 - %012.0d\n\n", x);
	
	printf("---%03.2d---\n", 1); 
	
	printf("%012d\n", y);
	printf("%010d\n", y);
	printf("%12d\n", y);
	printf("%+12d\n", y);
	printf("%+012d\n", y);
	printf("%0+12d\n", y);
	printf("%-12d\n", y);
	printf("%- 12d\n", y);
	printf("%-+12d\n", y);
	printf("%12.4d\n", y);
	printf("%-12.0d\n", y);
	printf("%-12.2d\n", y);
	printf("%-12.4d\n", y);
	printf("%012.0d\n", y);
1 - -00000000045
2 - -000000045
3 -          -45
4 -          -45
5 - -00000000045
6 - -00000000045
7 - -45
8 - -45
9 - -45
1 -        -0045
2 - -45
3 - -45
4 - -0045
5 -          -45
ft_printf("5 - %012.0d\n\n", x);

*/