#include <stdio.h>
#include <stdlib.h>

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

int		main(void)
{
	size_t x = 9223372036854775807;
	printf("%s\n", ft_lutoa_base(x, 8, 'A'));

/*
	int x = -45;

	printf("%12d\n", x);
	printf("%012d\n", x);
	printf("% 012d\n", x);
	printf("%+12d\n", x);
	printf("%+012d\n", x);
	printf("%0+12d\n", x);
	printf("%-12d\n", x);
	printf("%- 12d\n", x);
	printf("%-+12d\n", x);
	printf("%12.4d\n", x);
	printf("%-12.0d\n\n", x);
	printf("%012.0d\n", x);
	printf("%lu\n", sizeof(short));
*/
}