#include "includes/ft_printf.h"

int	ft_proc_char(char c, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	res = ft_proc_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (res + 1);
}
