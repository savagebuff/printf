#include "includes/ft_printf.h"

int	ft_put_pointer(char *pointer, t_flags flags)
{
	int	res;

	res = 0;
	res += ft_put_prec("0x", 2);
	if (flags.dot >= 0)
	{
		res += ft_proc_width(flags.dot, ft_strlen(pointer), 1);
		res += ft_put_prec(pointer, flags.dot);
	}
	else
		res += ft_put_prec(pointer, ft_strlen(pointer));
	return (res);
}

char	*ft_proc_base(unsigned long save, int base, char *tmp, int res)
{
	while (save != 0)
	{
		if ((save % base) < 10)
			tmp[res - 1] = (save % base) + 48;
		else
			tmp[res - 1] = (save % base) + 55;
		save /= base;
		res--;
	}
	return (tmp);
}

char	*ft_ul_base(unsigned long ul, int base)
{
	char			*tmp;
	unsigned long	save;
	int				res;

	tmp = 0;
	save = ul;
	res = 0;
	if (ul == 0)
		return (ft_strdup("0"));
	while (ul != 0)
	{
		ul /= base;
		res++;
	}
	tmp = malloc(sizeof(char) * (res + 1));
	if (!tmp)
		return (0);
	tmp[res] = '\0';
	tmp = ft_proc_base(save, base, tmp, res);
	return (tmp);
}

static int	ft_check_pointer(unsigned long ul, t_flags flags)
{
	int	res;

	res = 0;
	if (ul == 0 && flags.dot == 0)
	{
		if (flags.minus == 0)
		{
			res += ft_proc_width(flags.width - 1, 1, 0);
			res += ft_put_prec("0x", 2);
		}
		else
		{
			res += ft_put_prec("0x", 2);
			res += ft_proc_width(flags.width - 1, 1, 0);
		}
	}
	return (res);
}

int	ft_proc_pointer(unsigned long ul, t_flags flags)
{
	int		res;
	char	*pointer;

	res = ft_check_pointer(ul, flags);
	if (res != 0)
		return (res);
	pointer = ft_ul_base(ul, 16);
	pointer = ft_tolower_str(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		res += ft_put_pointer(pointer, flags);
	res += ft_proc_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		res += ft_put_pointer(pointer, flags);
	free (pointer);
	return (res);
}
