/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:37:09 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 18:37:11 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_octal_pref(size_t value, t_flags *f)
{
	if (f->hash && !f->f_prcsn && value != 0)
		return ("0");
	else if (f->hash && f->f_prcsn && f->prcsn == 0)
		return ("0");
	else if (f->hash && value > 0)
		return ("0");
	else
		return ("");
}

void		print_octal(t_flags *f)
{
	size_t	value;
	char	*s;
	int		len;
	char	*prefix;

	(f->f_prcsn) ? f->zero = 0 : 0;
	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 8, 'a');
	(f->f_prcsn && f->prcsn == 0 && value == 0) ? s = NULL : 0;
	prefix = get_octal_pref(value, f);
	len = ((int)ft_strlen(s) + (int)ft_strlen(prefix) > f->prcsn) ?\
(int)ft_strlen(s) + (int)ft_strlen(prefix) : f->prcsn;
	if (!f->minus && !f->zero)
		print_padding(f->width, len, ' ', f);
	write(1, prefix, (int)ft_strlen(prefix));
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len, '0', f);
	if (f->prcsn > (int)ft_strlen(s))
		print_padding(f->prcsn, (int)ft_strlen(s) + (int)ft_strlen(prefix),\
'0', f);
	write(1, s, (int)ft_strlen(s));
	if (f->minus)
		print_padding(f->width, len, ' ', f);
	f->num_printed += (int)ft_strlen(s) + (int)ft_strlen(prefix);
	ft_strdel(&s);
}
