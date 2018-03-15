/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:09:19 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 19:09:27 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_wslen_prcsn(int precision, wchar_t *wstr)
{
	int		n;
	size_t	i;

	i = 0;
	while (*wstr)
	{
		n = get_wclen(*wstr);
		if (precision - n >= 0)
		{
			precision -= n;
			i += (unsigned)n;
		}
		else
			return (i);
		wstr++;
	}
	return (i);
}

static size_t	get_wslen(wchar_t *wstr)
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

void			print_wstr(t_flags *f)
{
	wchar_t	*wstr;
	size_t	len1;
	size_t	len2;
	size_t	n;

	wstr = va_arg(f->ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	len1 = (f->f_prcsn) ? count_wslen_prcsn((int)f->prcsn, wstr) :\
	get_wslen(wstr);
	len2 = len1;
	if (!f->minus)
		print_padding(f->width, len1, (f->zero ? '0' : ' '), f);
	while (*wstr && len2 > 0)
	{
		n = ft_putwchar(*wstr++);
		f->num_printed += n;
		len2 -= n;
	}
	if (f->minus)
		print_padding(f->width, len1, ' ', f);
}
