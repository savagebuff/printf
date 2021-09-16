#include "includes/ft_printf.h"

static int	ft_two_put_int(char *d_i, int save, t_flags flags)
{
	int	res;

	res = 0;
	if (save < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		res += ft_proc_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	res += ft_put_prec(d_i, ft_strlen(d_i));
	return (res);
}

static int	ft_put_int(char *d_i, int save, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.minus == 1)
		res += ft_two_put_int(d_i, save, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		res += ft_proc_width(flags.width, 0, 0);
	}
	else
	{
		if (flags.width > 0 && flags.minus == 1)
			flags.zero = 0;
		res += ft_proc_width(flags.width, ft_strlen(d_i), flags.zero);
	}
	if (flags.minus == 0)
		res += ft_two_put_int(d_i, save, flags);
	return (res);
}

int	ft_proc_int(int i, t_flags flags)
{
	int			res;
	long long	save;
	char		*d_i;

	save = i;
	res = 0;
	if (flags.dot == 0 && i == 0)
	{
		res += ft_proc_width(flags.width, 0, 0);
		return (res);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot <= -1)
			ft_put_prec("-", 1);
		save *= -1;
		flags.zero = 1;
		flags.width--;
		res++;
	}
	d_i = ft_itoa(save);
	res += ft_put_int(d_i, i, flags);
	free(d_i);
	return (res);
}
