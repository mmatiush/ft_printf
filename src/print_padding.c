#include "ft_printf.h"

void		print_padding(int width, int print_len, char symbol, t_flags *f)
{
	while(print_len < width)
	{
		ft_putchar(symbol);
		print_len++;
		f->num_printed++;
	}
}