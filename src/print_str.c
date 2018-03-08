#include "ft_printf.h"

size_t	get_wslen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (*wstr)
	{
		i += get_wclen(*wstr);
		wstr++;
	}
	return (i);
}

void	print_wstr(t_flags *f)
{
	wchar_t	*wstr;
	int		len;

	wstr = va_arg(f->ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	len = get_wslen(wstr);
	if (!f->minus)
		print_padding(f->width, len, (f->zero ? '0' : ' '), f);
	while(*wstr)
	{
		ft_putwchar(*wstr);
		wstr++;
	}
	f->num_printed = f->num_printed + len;
	if(f->minus)
		print_padding(f->width, len, ' ', f);
}

void	print_str(t_flags *f)
{
	char	*str;
	int		len;

	if (f->l)
	{
		print_wstr(f);
		return ;
	}
	str = va_arg(f->ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (f->f_prcsn)
		(f->prcsn < len) ? len = f->prcsn : 0;
	if (!f->minus)
		print_padding(f->width, len, (f->zero ? '0' : ' '), f);
	write(1, str, len);
	f->num_printed = f->num_printed + len;
	if(f->minus)
		print_padding(f->width, len, ' ', f);
}
