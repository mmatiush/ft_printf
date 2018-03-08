#include "ft_printf.h"

/*
** Transfers unsigned long int to a string by a base.
** The third agrument is either 'A' or 'a' depending on agrument received
** by ft_printf. For base < 10 it's ignored.
*/

char	*ft_lutoa_base(size_t value, int base, char c)
{
	char	*s;
	size_t 	n;
	int		i;

	n = value;
	i = 1;
	while ((value /= base) > 0)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
		n /= base;
	}
	return (s);
}

ssize_t	get_decimal_fl(t_flags *f)
{
	ssize_t	value;

	if (f->l)
		value = va_arg(f->ap, long int);
	else if (f->ll)
		value = va_arg(f->ap, long long int);
	else if (f->h)
		value = (short)va_arg(f->ap, int);
	else if (f->hh)
		value = (char)va_arg(f->ap, int);
	else if (f->j)
		value = va_arg(f->ap, intmax_t);
	else if (f->z)
		value = va_arg(f->ap, size_t);
	else
		value = va_arg(f->ap, int);
	return (value);
}

char	*get_decimal_pref(ssize_t value, t_flags *f)
{
	char	*prefix;

	if (value < 0)
		prefix = "-";
	else if (value >= 0 && f->plus)
		prefix = "+";
	else if (value >= 0 && f->space && !f->plus)
		prefix = " ";
	else
		prefix = "";
	return (prefix);
}

void	print_decimal(t_flags *f)
{
	ssize_t			value;
	char			*s;
	int				len;
	char			*prefix;

	value = get_decimal_fl(f);
	s = ft_lutoa_base((value < 0) ? -(size_t)value : (size_t)value, 10, 'a');
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = ((int)ft_strlen(s) > f->prcsn) ? (int)ft_strlen(s) : f->prcsn;
	prefix = get_decimal_pref(value, f);
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus && !f->zero)
		print_padding(f->width, len + (int)ft_strlen(prefix), ' ', f);
	ft_putstr(prefix);
	f->num_printed = f->num_printed + (int)ft_strlen(prefix);
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len + (int)ft_strlen(prefix), '0', f);
	if (f->prcsn > (int)ft_strlen(s))
		print_padding(f->prcsn, (int)ft_strlen(s), '0', f);
	ft_putstr(s);
	f->num_printed = f->num_printed + ft_strlen(s);
	if (f->minus)
		print_padding(f->width, len + (int)ft_strlen(prefix), ' ', f);
	ft_strdel(&s);
}
/*
padding(' ') - prefix - paddding('0')  - prcsn - number - padding


width
prcsn
space
zero
minus
plus

F.PLUS = F.SPACE = ZERO 

*/