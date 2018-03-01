#include "ft_printf.h"

void	print_d(t_flags *f)
{
	int_max		n;

	if (f->l)
		n = va_arg(f->ap, long int);
	if (f->ll)
		n = va_arg(f->ap, long long int);
	if (f->h)
		n = va_arg(f->ap, short);

}