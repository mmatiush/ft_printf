/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:13 by mmatiush          #+#    #+#             */
/*   Updated: 2018/03/12 20:36:14 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints unsigned long int in binary.
*/

void	print_binary(t_flags *f)
{
	size_t	value;
	char	*s;
	int		len;

	value = get_unsigned_fl(f);
	s = ft_lutoa_base(value, 2, 'a');
	(value == 0 && f->f_prcsn) ? s = NULL : 0;
	len = ((int)ft_strlen(s) > f->prcsn) ? (int)ft_strlen(s) : f->prcsn;
	(f->f_prcsn) ? f->zero = 0 : 0;
	if (!f->minus && !f->zero)
		print_padding(f->width, len, ' ', f);
	if (!f->minus && f->zero && !f->f_prcsn)
		print_padding(f->width, len, '0', f);
	if (f->prcsn > (int)ft_strlen(s))
		print_padding(f->prcsn, (int)ft_strlen(s), '0', f);
	write(1, s, (int)ft_strlen(s));
	if (f->minus)
		print_padding(f->width, len, ' ', f);
	f->num_printed += (int)ft_strlen(s);
	ft_strdel(&s);
}
