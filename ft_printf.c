#include "ft_printf.h"

void	start_printing()
{
	if (*f.fmt == 'd')
		ft_putnbr(va_arg(f.ap, int));
	if (*f.fmt == 'c')
		ft_putchar(va_arg(f.ap, int));
	if (*f.fmt == 's')
		ft_putstr(va_arg(f.ap, char*));
}

int		equals_spec(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||\
		c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	else
		return (0);
}
void	read_format_2()
{
		f.j = (*f.fmt == 'j') ? 1 : 0;
		f.z = (*f.fmt == 'z') ? 1 : 0;
		(f.hh) ? f.h = 0 : 0;
		(f.ll) ? f.l = 0 : 0;
		f.hash = (*f.fmt == '#') ? 1 : 0;
		f.minus = (*f.fmt == '-') ? 1 : 0;
		f.plus = (*f.fmt == '+') ? 1 : 0;
		f.zero = (*f.fmt == '0') ? 1 : 0;
		f.space = (*f.fmt == ' ') ? 1 : 0;
		f.f_prcsn = (*f.fmt == '.') ? 1 : 0;
		if (ft_isdigit(*f.fmt) && *f.fmt != '0' && f.f_prcsn)
		{
			f.prcsn = ft_atoi(f.fmt);
			while (ft_isdigit(*f.fmt))
				f.fmt++;
		}
		if (ft_isdigit(*f.fmt) && *f.fmt != '0' && !f.f_prcsn)
		{
			f.width = ft_atoi(f.fmt);
			while (ft_isdigit(*f.fmt))
				f.fmt++;
		}
}

/*
** Read fomat started when a % was encountered. It will process wile formar
** doesn't equal a specifier and while format exists
*/

void	read_format_1()
{
	while (!(equals_spec(*f.fmt)) && *f.fmt)
	{
		f.prev_format = f.fmt - 1;
		if (*f.fmt == '%')
		{
			ft_putchar('%');
			f.num_printed++;
			return ;
		}
		if (*f.fmt == '*' && f.f_prcsn)
			f.prcsn = va_arg(f.ap, int);
		if (*f.fmt == '*' && !f.f_prcsn)
			f.width = va_arg(f.ap, int);
		f.h = (*f.fmt == 'h') ? 1 : 0;
		f.l = (*f.fmt == 'l') ? 1 : 0;
		f.hh = (*f.fmt == 'h' && *f.prev_format == 'h') ? 1 : 0;
		f.ll = (*f.fmt == 'l' && *f.prev_format == 'l') ? 1 : 0;
		read_format_2();
	}
	if (*f.fmt)
		f.specifier = *f.fmt;
}

int		ft_printf(const char *format, ...)
{
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
			clr_flags();
			f.fmt++;
			read_format_1();
			start_printing();
		}
		f.fmt++;
	}
}
