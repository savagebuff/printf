#include "includes/ft_printf.h"
#include <stdio.h>

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.dot = -1;
	flags.type = 0;
	flags.width = 0;
	return (flags);
}

int	ft_check_what_type(const char *s, int i, t_flags flags, va_list args)
{
	int	len;
	int	res;

	res = 0;
	if (ft_what_type(s[i]))
	{
		len = ft_translator((char)flags.type, flags, args);
		if (len == -1)
			return (-1);
		res += len;
	}
	else if (s[i] != '\0')
		res += ft_putchar(i);
	return (res);
}

int	ft_parse_args(va_list args, const char *s)
{
	int		i;
	t_flags	flags;
	int		res;
	int		len;

	i = -1;
	res = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			flags = ft_init_flags();
			i = ft_parse_flags(s, i, &flags, args);
			len = ft_check_what_type(s, i, flags, args);
			if (len == -1)
				return (-1);
			res += len;
		}
		else if (s[i] != '%')
			res += ft_putchar(s[i]);
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		res;

	if (!s)
		return (-1);
	va_start(args, s);
	res = ft_parse_args(args, s);
	va_end(args);
	return (res);
}
