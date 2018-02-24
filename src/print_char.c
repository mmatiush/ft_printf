#include "ft_printf.h"

/*void	print_wchar(t_flags *f)
{

}*/

void	print_char(t_flags *f)
{
	/*if (f->l)
	{
		print_wchar(&f);
		return ;
	}*/
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), &*f);
	ft_putchar(va_arg(f->ap, int));
	f->num_printed++;
	if (f->minus)
		print_padding(f->width, 1, ' ', &*f);
}