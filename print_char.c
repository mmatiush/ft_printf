#include "ft_printf.h"

void	print_wchar(t_flags *f)
{

}

void	print_char(t_flags *f)
{
	if (f->l)
	{
		print_wchar(&f);
		return ;
	}
	(f->) ? print_padding();
	ft_putchar(va_arg(f->ap, int));
	print_padding();
}