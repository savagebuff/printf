#include "includes/ft_printf.h"

static int	ft_two_put_hexa(char *hexa, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.dot >= 0)
		res += ft_proc_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	res += ft_put_prec(hexa, ft_strlen(hexa));
	return (res);
}

static int	ft_put_hexa(char *hexa, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.minus == 1)
		res += ft_two_put_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		res += ft_proc_width(flags.width, 0, 0);
	}
	else
	{
		if (flags.width > 0 && flags.minus == 1)
			flags.zero = 0;
		res += ft_proc_width(flags.width, ft_strlen(hexa), flags.zero);
	}
	if (flags.minus == 0)
		res += ft_two_put_hexa(hexa, flags);
	return (res);
}

int	ft_proc_hexa(unsigned int uns_int, int lower, t_flags flags)
{
	char	*hexa;
	int		res;

	res = 0;
	uns_int = (unsigned int)(4294967295 + 1 + uns_int);
	if (flags.dot == 0 && uns_int == 0)
	{
		res += ft_proc_width(flags.width, 0, 0);
		return (res);
	}
	hexa = ft_ul_base((unsigned long)uns_int, 16);
	if (lower == 1)
		hexa = ft_tolower_str(hexa);
	res += ft_put_hexa(hexa, flags);
	free(hexa);
	return (res);
}
