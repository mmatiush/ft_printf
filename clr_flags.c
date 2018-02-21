#include "ft_printf.h"

void	clr_flags()
{


	f.specifier = 0;		
	f.width = 0;
	f.prcsn = 0;
	
	f.prev_format = 0;

	f.hash = 0;
	f.minus = 0;
	f.plus = 0;
	f.zero = 0;
	f.space = 0;
	f.f_prcsn = 0;
	
	f.hh = 0;
	f.h = 0;
	f.ll = 0;
	f.l = 0;
	f.j = 0;
	f.z = 0;
}