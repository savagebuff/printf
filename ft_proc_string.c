#include "includes/ft_printf.h"

int	ft_put_string(char *str, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.dot >= 0)
	{
		res += ft_proc_width(flags.dot, ft_strlen(str), 0);
		res += ft_put_prec(str, flags.dot);
	}
	else
		res += ft_put_prec(str, ft_strlen(str));
	return (res);
}

char	*ft_tolower_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	ft_proc_string(char *str, t_flags flags)
{
	int	res;

	res = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && ((size_t)flags.dot > ft_strlen(str)))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		res += ft_put_string(str, flags);
	if (flags.dot >= 0)
		res += ft_proc_width(flags.width, flags.dot, 0);
	else
		res += ft_proc_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		res += ft_put_string(str, flags);
	return (res);
}
