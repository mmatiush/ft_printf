#include "ft_printf.h"

size_t	get_unsigned_fl(t_flags *f)
{
	size_t	value;

	if (f->l)
		value = va_arg(f->ap, long unsigned);
	else if (f->ll)
		value = va_arg(f->ap, long long unsigned);
	else if (f->h)
		value = (unsigned short)va_arg(f->ap, unsigned);
	else if (f->hh)
		value = (unsigned char)va_arg(f->ap, unsigned);
	else if (f->j)
		value = va_arg(f->ap, uintmax_t);
	else if (f->z)
		value = va_arg(f->ap, size_t);
	else
		value = va_arg(f->ap, unsigned);
	return (value);
}


void	print_unsigned(t_flags *f)
{
	size_t			value;
	char			*s;
	int				len;

	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 10, 'a');
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = ((int)ft_strlen(s) > f->prcsn) ? (int)ft_strlen(s) : f->prcsn;
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus)
		print_padding(f->width, len, (f->zero ? '0' : ' '), f);
	if (f->prcsn > (int)ft_strlen(s))
		print_padding(f->prcsn, (int)ft_strlen(s), '0', f);
	write(1, s, ft_strlen(s));
	f->num_printed = f->num_printed + ft_strlen(s);
	if(f->minus)
		print_padding(f->width, len, ' ', f);
	ft_strdel(&s);
}
