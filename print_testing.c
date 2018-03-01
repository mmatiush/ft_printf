#include <unistd.h>
#include <stdio.h>

int		get_wlen(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 61439)
		return (3);
	else
		return (4);
}

int		main(void)
{
	unsigned int	wc = L'𐍈';
	int				w_len;
	unsigned char	octet[4];

	w_len = get_wlen(wc);
	int i = 0;
	printf("%d\n", w_len);
	if (w_len == 1)
		octet[0] = wc;
	else if (w_len == 2)
	{
		octet[0] = 0xC0 | ((wc >> 6) & 0x1F);
		octet[1] = 0x80 | (wc & 0x3F);
	}
	else if (w_len == 3)
	{
		octet[0] = 0xE0 | ((wc >> 12) & 0x0F);
		octet[1] = 0x80 | ((wc >> 6) & 0x3F);
		octet[2] = 0x80 | (wc & 0x3F);
	}
	else if (w_len == 4)
	{
		octet[0] = 0xF0 | (wc >> 18) & 0x07;
		octet[1] = 0x80 | ((wc >> 12) & 0x3F);
		octet[2] = 0x80 | ((wc >> 6) & 0x3F);
		octet[3] = 0x80 | (wc & 0x3F);
	}
	write(1, &octet[0], w_len);
/*
2 - α
3 - 的
4 - 𐍈
*/

}