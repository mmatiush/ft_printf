#include "ft_printf.h"

void	start_printing(t_flags *f)
{
	if (f->specifier == 'D' || f->specifier == 'U' || f->specifier == 'O')
		f->l = 1;
	if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'D')
		print_decimal(f);
 	(f->specifier == 'u' || f->specifier == 'U') ? print_unsigned(f) : 0;
	(f->specifier == 'o' || f->specifier == 'O') ? print_octal(f) : 0;
	(f->specifier == 'c') ? print_char(f) : 0;
	(f->specifier == 'C') ? print_wchar(f) : 0;
	(f->specifier == 's') ? print_str(f) : 0;
	(f->specifier == 'S') ? print_wstr(f) : 0;
	(f->specifier == 'x' || f->specifier == 'X') ? print_hexadecimal(f) : 0;
	(f->specifier == '%') ? print_percent(f) : 0;
	if (f->specifier == 'p')
		{
			f->hash = 1;
			f->j = 1;
			print_hexadecimal(f);
		}
	if (!equals_spec(f->specifier) && f->specifier)
		print_invalid_specifier(f);
}

/*
** Function to check specifier. Returns 1 if char equals one of the sepcifiers.
*/

int		equals_spec(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||\
		c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	else
		return (0);
}

void	read_format_2(t_flags *f)
{
		(*f->fmt == 'j') ? f->j = 1 : 0;
		(*f->fmt == 'z') ? f->z = 1 : 0;
		(f->hh) ? f->h = 0 : 0;
		(f->ll) ? f->l = 0 : 0;
		(*f->fmt == '#') ? f->hash = 1 : 0;
		(*f->fmt == '-') ? f->minus = 1 : 0;
		(*f->fmt == '+') ? f->plus = 1 : 0;
		(*f->fmt == '0') ? f->zero = 1 : 0;
		(*f->fmt == ' ') ? f->space = 1 : 0;
		if (ft_isdigit(*f->fmt) && *f->fmt != '0' && f->f_prcsn)
		{
			f->prcsn = ft_atoi(f->fmt);
			while (ft_isdigit(*f->fmt))
				f->fmt++;
			f->fmt--;
		}
		if (ft_isdigit(*f->fmt) && *f->fmt != '0' && !f->f_prcsn)
		{
			f->width = ft_atoi(f->fmt);
			while (ft_isdigit(*f->fmt))
				f->fmt++;
			f->fmt--;
		}
		f->fmt++;
}

/*
** Read fomat started when a % was encountered. It will process wile format
** doesn't equal a specifier and while format exists
*/

void	read_format_1(t_flags *f)
{
	const char	*prev_format;

	while (*f->fmt && ft_strchr("hljz0#+-. *1234567890", *f->fmt))
	{
		prev_format = f->fmt - 1;
		if (*f->fmt == '.')
			{
				(f->f_prcsn = 1);
				(f->prcsn = 0);
			}
		if (*f->fmt == '*' && !f->f_prcsn)
		{
			f->width = va_arg(f->ap, int);
			(f->width < 0) ? f->minus = 1 : 0;
			(f->width < 0) ? f->width = -f->width : 0;
		}
		if (*f->fmt == '*' && f->f_prcsn)
		{
			f->prcsn = va_arg(f->ap, int);
			if (f->prcsn < 0)
			{
				f->prcsn = 0;
				f->f_prcsn = 0;
			}
		}
		(*f->fmt == 'h') ? f->h = 1 : 0;
		(*f->fmt == 'l') ? f->l = 1 : 0;
		(*f->fmt == 'h' && *prev_format == 'h') ? f->hh = 1 : 0;
		(*f->fmt == 'l' && *prev_format == 'l') ? f->ll = 1 : 0;
		read_format_2(f);
	}
	if (*f->fmt)
		f->specifier = *f->fmt;
	else
		f->fmt--;
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
