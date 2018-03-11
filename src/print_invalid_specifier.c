#include "ft_printf.h"

void	print_invalid_specifier(t_flags *f)
{
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), f);
	ft_putchar(f->specifier);
	f->num_printed++;
	if(f->minus)
		print_padding(f->width, 1, ' ', f);
}