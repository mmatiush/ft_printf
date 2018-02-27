#include "ft_printf.h"

/*
** The function accepts width flag, length of print parameter, printing
** symbol ' ' or '0', pointer to structure.
** The function prints width - print_len bytes;
*/

void		print_padding(int width, int print_len, char symbol, t_flags *f)
{
	while (print_len < width)
	{
		ft_putchar(symbol);
		print_len++;
		f->num_printed++;
	}
}
