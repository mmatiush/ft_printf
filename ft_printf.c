#include "ft_printf.h"

void	start_printing(t_flags *f)
{
	if (*f->fmt == 'd')
		ft_putnbr(va_arg(f->ap, int));
	if (*f->fmt == 'c')
		print_char(&f);
	if (*f->fmt == 's')
		ft_putstr(va_arg(f->ap, char*));
}

/*
** Function to check spcifier. Returns 1 if char equals one sepcifiers.
*/
int		equals_spec(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||\
		c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}
void	read_format_2(t_flags *f)
{
		f->j = (*f->fmt == 'j') ? 1 : 0;
		f->z = (*f->fmt == 'z') ? 1 : 0;
		(f->hh) ? f->h = 0 : 0;
		(f->ll) ? f->l = 0 : 0;
		f->hash = (*f->fmt == '#') ? 1 : 0;
		f->minus = (*f->fmt == '-') ? 1 : 0;
		f->plus = (*f->fmt == '+') ? 1 : 0;
		f->zero = (*f->fmt == '0') ? 1 : 0;
		f->space = (*f->fmt == ' ') ? 1 : 0;
		f->f_prcsn = (*f->fmt == '.') ? 1 : 0;
		if (ft_isdigit(*f->fmt) && *f->fmt != '0' && f->f_prcsn)
		{
			f->prcsn = ft_atoi(f->fmt);
			while (ft_isdigit(*f->fmt))
				f->fmt++;
		}

		if (ft_isdigit(*f->fmt) && *f->fmt != '0' && !f->f_prcsn)
		{
			f->width = ft_atoi(f->fmt);
			while (ft_isdigit(*f->fmt))
				f->fmt++;
		}
}

/*
** Read fomat started when a % was encountered. It will process wile format
** doesn't equal a specifier and while format exists
*/

void	read_format_1(t_flags *f)
{
	const char	*prev_format;

	while (!(equals_spec(*f->fmt)) && *f->fmt)
	{
		prev_format = f->fmt - 1;
		if (*f->fmt == '%')
		{
			ft_putchar('%');
			f->num_printed++;
			return ;
		}
		if (*f->fmt == '*' && f->f_prcsn)
			f->prcsn = va_arg(f->ap, int);
		if (*f->fmt == '*' && !f->f_prcsn)
			f->width = va_arg(f->ap, int);
		f->h = (*f->fmt == 'h') ? 1 : 0;
		f->l = (*f->fmt == 'l') ? 1 : 0;
		f->hh = (*f->fmt == 'h' && *prev_format == 'h') ? 1 : 0;
		f->ll = (*f->fmt == 'l' && *prev_format == 'l') ? 1 : 0;
		read_format_2(f);
	}
	if (*f->fmt)
		f->specifier = *f->fmt;
}

int		ft_printf(const char *format, ...)
{
	t_flags	f;

	f.fmt = format;
	f.num_printed = 0;
	va_start(f.ap, format);
	while (*f.fmt)
	{
		if (*f.fmt != '%')
		{
			ft_putchar(*f.fmt);
			f.num_printed++;
		}
		else
		{
			clr_flags(&f);
			f.fmt++;
			read_format_1(&f);
			start_printing(&f);
		}
		f.fmt++;
	}
	return (f.num_printed);
}
