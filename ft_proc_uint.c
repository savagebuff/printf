#include "includes/ft_printf.h"

static int	ft_two_put_uint(char *tmp, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.dot >= 0)
		res += ft_proc_width(flags.dot - 1, ft_strlen(tmp) - 1, 1);
	res += ft_put_prec(tmp, ft_strlen(tmp));
	return (res);
}

static int	ft_put_uint(char *tmp, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.minus == 1)
		res += ft_two_put_uint(tmp, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(tmp))
		flags.dot = ft_strlen(tmp);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		res += ft_proc_width(flags.width, 0, 0);
	}
	else
	{
		if (flags.width > 0 && flags.minus == 1)
			flags.zero = 0;
		res += ft_proc_width(flags.width, ft_strlen(tmp), flags.zero);
	}
	if (flags.minus == 0)
		res += ft_two_put_uint(tmp, flags);
	return (res);
}

int	ft_proc_uint(unsigned int uns_int, t_flags flags)
{
	char	*tmp;
	int		res;

	res = 0;
	uns_int = (unsigned int)(4294967295 + 1) + uns_int;
	if (flags.dot == 0 && uns_int == 0)
	{
		res += ft_proc_width(flags.width, 0, 0);
		return (res);
	}
	tmp = ft_uns_itoa(uns_int);
	res += ft_put_uint(tmp, flags);
	free(tmp);
	return (res);
}
