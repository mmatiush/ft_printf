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
	int		len;

	wstr = va_arg(f->ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	len = get_wslen(wstr);
	if (!f->minus)
		print_padding(f->width, len, (f->zero ? '0' : ' '), f);
	while (*wstr)
	{
		ft_putwchar(*wstr);
		wstr++;
	}
	f->num_printed = f->num_printed + len;
	if (f->minus)
		print_padding(f->width, len, ' ', f);
}
