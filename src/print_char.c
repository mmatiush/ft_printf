#include "ft_printf.h"

/*
** Check how many bytes needed for printing wide char
*/
int		get_wlen(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 61439)
		return (3);
	else
		return (4);
}

/*
** Converts wide char to multibyte char depending on how many bytes needed.
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/
void	ft_wctomb(unsigned char (*octet)[4], unsigned wc, int w_len)
{
	if (w_len == 1)
		(*octet)[0] = wc;
	else if (w_len == 2)
	{
		(*octet)[0] = 0xC0 | ((wc >> 6) & 0x1F);
		(*octet)[1] = 0x80 | (wc & 0x3F);
	}
	else if (w_len == 3)
	{
		(*octet)[0] = 0xE0 | ((wc >> 12) & 0x0F);
		(*octet)[1] = 0x80 | ((wc >> 6) & 0x3F);
		(*octet)[2] = 0x80 | (wc & 0x3F);
	}
	else if (w_len == 4)
	{
		(*octet)[0] = 0xF0 | ((wc >> 18) & 0x07);
		(*octet)[1] = 0x80 | ((wc >> 12) & 0x3F);
		(*octet)[2] = 0x80 | ((wc >> 6) & 0x3F);
		(*octet)[3] = 0x80 | (wc & 0x3F);
	}
}

void	print_wchar(t_flags *f)
{
	unsigned int	wc;
	int				w_len;
	unsigned char	octet[4];

	wc = va_arg(f->ap, unsigned int);
	w_len = get_wlen(wc);
	ft_wctomb(&octet, wc, w_len);
	if (!f->minus)
		print_padding(f->width, w_len, (f->zero ? '0' : ' '), &*f);
	write(1, &octet[0], w_len);
	f->num_printed = f->num_printed + w_len;
	if (f->minus)
		print_padding(f->width, w_len, ' ', &*f);
}

void	print_char(t_flags *f)
{
	if (f->l)
	{
		print_wchar(*&f);
		return ;
	}
	if (!f->minus)
		print_padding(f->width, 1, (f->zero ? '0' : ' '), &*f);
	ft_putchar(va_arg(f->ap, int));
	f->num_printed++;
	if (f->minus)
		print_padding(f->width, 1, ' ', &*f);
}