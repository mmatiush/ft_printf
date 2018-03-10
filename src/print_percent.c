#include "ft_printf.h"

void	print_percent(t_flags *f)
{
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), f);
	write(1, "%", 1);
	f->num_printed++;
	if(f->minus)
		print_padding(f->width, 1, ' ', f);
}
