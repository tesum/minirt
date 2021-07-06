#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_arg
{
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		widht;
	int		precision;
	int		len_skip;
	int		len;
	char	type;
}				t_arg;

int		ft_printf(const char *format, ...);

void	main_procces(va_list ap, t_arg *arg);
void	procces_c(int c, t_arg *arg);
void	procces_s(char *str, t_arg *arg);
void	procces_d(int num, t_arg *arg);
void	procces_x(unsigned int num, t_arg *arg, int upper);
void	procces_p(unsigned long long num, t_arg *arg);
void	procces_u(unsigned long num, t_arg *arg);
void	procces_procent(t_arg *arg);
t_arg	format_change(const char *format, va_list ap, int i, t_arg *arg);

void	init_arg(t_arg *arg, int len);
void	print_zero(int count, t_arg *arg);
void	print_space(int count, t_arg *arg);
void	print_minus(unsigned int num, char *numc, int len, t_arg *arg);
void	print_w_minus(unsigned int num, char *numc, int len, t_arg *arg);
char	*to_hex(unsigned long long num, int upper);

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		div_malloc(long int n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
int		neg_w_minus(char *numc, t_arg *arg, int len);
int		neg_minus(char *numc, t_arg *arg, int len);

#endif