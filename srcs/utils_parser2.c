/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:22:06 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 17:47:09 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	continue_atof(char **str, double *number)
{
	int		k;

	k = 10;
	if (**str == '.')
	{
		*str += 1;
		while (**str && ft_isdigit(**str))
		{
			*number = *number + (double)(**str - '0') / k;
			*str += 1;
			k *= 10;
		}
	}
}

double	ft_atof(char **str)
{
	double	number;
	int		m;

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
	continue_atof(str, &number);
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
	printf("Error\n%s\n", error);
	exit(code);
}
