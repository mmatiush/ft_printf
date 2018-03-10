#include "ft_printf.h"

char	*get_octal_pref(t_flags *f)
{
	if (f->hash)
		return ("0");
	else
		return ("");
}

void	print_octal(t_flags *f)
{
	size_t	value;
	char	*s;
	int		len;
	char	*prefix;

	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 8, 'a');
	prefix = get_octal_pref(f);
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = ((int)ft_strlen(s) > f->prcsn) ? (int)ft_strlen(s) : f->prcsn;
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus && !f->zero)
		print_padding(f->width, len + (int)ft_strlen(prefix), ' ', f);
	write(1, prefix, (int)ft_strlen(prefix));
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len + (int)ft_strlen(prefix), '0', f);
	if (f->prcsn > (int)ft_strlen(s))
		print_padding(f->prcsn, (int)ft_strlen(s), '0', f);
	write(1, s, (int)ft_strlen(s));
	if (f->minus)
		print_padding(f->width, len + (int)ft_strlen(prefix), ' ', f);
	f->num_printed += (int)ft_strlen(s) + (int)ft_strlen(prefix);
	ft_strdel(&s);
}