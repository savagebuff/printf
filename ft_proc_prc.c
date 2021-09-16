#include "includes/ft_printf.h"

int	ft_put_prec(char *str, int prec)
{
	int	i;

	i = 0;
	while (str[i] && i < prec)
		ft_putchar(str[i++]);
	return (i);
}

int	ft_proc_prc(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.minus == 1)
	{
		i += ft_put_prec("%", 1);
		flags.zero = 0;
	}
	i += ft_proc_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		i += ft_put_prec("%", 1);
	return (i);
}
