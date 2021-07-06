/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:43:06 by demilan           #+#    #+#             */
/*   Updated: 2021/04/24 00:21:01 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	check_max(long long result, int num, int minus)
{
	if (num > 11)
	{
		if (minus < 0)
			return (0);
		if (minus > 0)
			return (-1);
	}
	else
	{
		if (result < -2147483648)
			return (0);
		if (result > 2147483648)
			return (-1);
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			num;
	int			minus;
	long long	result;

	i = 0;
	num = 0;
	minus = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		minus = ',' - str[i];
		i++;
	}
	while ((*(str + i) >= '0' && *(str + i) <= '9'))
	{
		result = result * 10 + *(str + i) - '0';
		num++;
		i++;
	}
	result = check_max(result, num, minus);
	return (result * minus);
}
