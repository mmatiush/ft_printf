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
	s = (char*)malloc(sizeof(char) * (i + 1));
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
	else if (value > 0 && f->plus)
		prefix = "+";
	else if (value > 0 && f->space && !f->plus)
		prefix = " ";
	else
		prefix = "";
	return (prefix);
}

void	print_decimal(t_flags *f)
{
	ssize_t			value;
	size_t			n;
	char			*s;
	int				len;
	char			*prefix;

	value = get_decimal_fl(&*f);
	n = (value < 0) ? -(size_t)value : value;
	s = ft_lutoa_base(n, 10, 'a');
	len = ft_strlen(s);
	prefix = get_decimal_pref(value, &*f);
	

}
/*

width
precision
space
zero
minus
plus

F.PLUS = F.SPACE = ZERO 

*/