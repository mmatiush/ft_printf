#include <stdio.h>

int		main()
{
	char *ptr = "123456789";
	char *scndPtr;
	printf("%c\n", *ptr);
	ptr++;
	ptr++;
	printf("%c\n", *ptr);
	scndPtr = ptr - 1;
	printf("%c\n", *ptr);
	printf("%c\n", *scndPtr);


	return 0;
}