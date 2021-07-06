#include "miniRT.h"


double	ft_atof(char **str)
{
	size_t	i;
	double	number;
	int		m;

	i = 0;
	number = 0.0;
	m = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		m = -m;
		*str += 1;
	}
	while (**str != '\0' && ft_isdigit(**str))
	{
		number = number * 10.0 + (**str - '0');
		*str += 1;
	}
	if (**str == '.')
	{
		*str += 1;
		while (**str && ft_isdigit(**str))
		{
			number = number * 10.0 + (**str - '0');
			*str += 1;
		}
		number /= 10;
	}
	number *= m;
	return (number);
}

t_vec3	parse_vec3(char **str)
{
	t_vec3	vec;
	double	x;

	x = ft_atof(str);
	vec.x = x;
	if (**str == ',')
	{
		*str += 1;
		x = ft_atof(str);
		vec.y = x;
	}
	if (**str == ',')
	{
		*str += 1;
		x = ft_atof(str);
		vec.z = x;
	}
	return (vec);
}

void	exit_error(char *error, int code)
{
	perror(error);
	exit(code);
}