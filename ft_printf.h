#ifndef FT_PRINTF_H
 #define FT_PRINTF_H

#include <stdio.h>
#include "libft.h"
#include <stdarg.h>

#define ABS(x) (((x) < 0) ? (-x) : (x));

typedef struct	s_flags
{

	const char	*fmt;
	va_list		ap;
	int			num_printed;

	char		specifier;		
	int			width;
	int			prcsn;

	unsigned	hash:1;
	unsigned	minus:1;
	unsigned	plus:1;
	unsigned	zero:1;
	unsigned	space:1;
	unsigned	f_prcsn:1;
	
	unsigned	hh:1;
	unsigned	h:1;
	unsigned	ll:1;
	unsigned	l:1;
	unsigned	j:1;
	unsigned	z:1;
}				t_flags;

int		ft_printf(const char *format, ...);
void	clr_flags(t_flags *f);
int		equals_spec(const char c);
void	read_format_1(t_flags *f);
void	read_format_2(t_flags *f);

/*
** Print C
*/
void	print_char(t_flags *f);
void	print_padding(int width, int print_len, char symbol, t_flags *f);




#endif