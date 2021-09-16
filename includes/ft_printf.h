#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	star;
	int	dot;
	int	type;
	int	width;
}	t_flags;

int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_printf(const char *s, ...);
int		ft_parse_args(va_list args, const char *s);
int		ft_putchar(char c);
int		ft_what_type(int i);
int		ft_what_flag(int c);
int		ft_parse_flags(const char *s, int i, t_flags *flags, va_list args);
int		ft_flag_dot(const char *s, int i, t_flags *flags, va_list args);
int		ft_translator(int c, t_flags flags, va_list args);
int		ft_proc_prc(t_flags flags);
int		ft_proc_width(int width, int minus, int zero);
int		ft_put_prec(char *str, int prec);
int		ft_proc_int(int i, t_flags flags);
int		ft_proc_char(char c, t_flags flags);
int		ft_proc_string(char *str, t_flags flags);
int		ft_put_string(char *str, t_flags flags);
int		ft_proc_pointer(unsigned long ul, t_flags flags);
int		ft_put_pointer(char *pointer, t_flags flags);
int		ft_proc_uint(unsigned int uns_int, t_flags flags);
int		ft_proc_hexa(unsigned int uns_int, int lower, t_flags flags);
char	*ft_ul_base(unsigned long ul, int base);
char	*ft_proc_base(unsigned long save, int base, char *tmp, int res);
char	*ft_tolower_str(char *str);
char	*ft_uns_itoa(unsigned int n);
char	*ft_strdup(const char *str);
char	*ft_itoa(long long n);
size_t	ft_strlen(const char *str);
t_flags	ft_init_flags(void);
t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flags_width(t_flags flags, va_list args);
t_flags	ft_flag_digit(char c, t_flags flags);

#endif
