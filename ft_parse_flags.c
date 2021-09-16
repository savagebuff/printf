#include "includes/ft_printf.h"

int	ft_what_type(int i)
{
	return ((i == 'i') || (i == 'd') || (i == 'c') || (i == 's')
		|| (i == 'p') || (i == 'u') || (i == 'x') || (i == 'X') || (i == '%'));
}

int	ft_what_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int	ft_parse_flags(const char *s, int i, t_flags *flags, va_list args)
{
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && !ft_what_type(s[i]) && (s[i] != '-')
			&& (s[i] != '0') && (s[i] != '.') && (s[i] != '*'))
			break ;
		if (ft_isdigit(s[i]))
			*flags = ft_flag_digit(s[i], *flags);
		if (s[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (s[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (s[i] == '.')
			i = ft_flag_dot(s, i, flags, args);
		if (s[i] == '*')
			*flags = ft_flags_width(*flags, args);
		if (ft_what_type(s[i]))
		{
			flags->type = s[i];
			break ;
		}
		i++;
	}
	return (i);
}
