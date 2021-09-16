#include "includes/ft_printf.h"

int	ft_proc_width(int width, int minus, int zero)
{
	int	i;

	i = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		i++;
	}
	return (i);
}

int	ft_translator(int c, t_flags flags, va_list args)
{
	int	res;

	res = 0;
	if (c == '%')
		res += ft_proc_prc(flags);
	else if (c == 'd' || c =='i')
		res = ft_proc_int(va_arg(args, int), flags);
	else if (c == 'c')
		res = ft_proc_char(va_arg(args, int), flags);
	else if (c == 's')
		res = ft_proc_string(va_arg(args, char *), flags);
	else if (c == 'p')
		res = ft_proc_pointer(va_arg(args, unsigned long), flags);
	else if (c == 'u')
		res = ft_proc_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		res += ft_proc_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		res += ft_proc_hexa(va_arg(args, unsigned int), 0, flags);
	return (res);
}
