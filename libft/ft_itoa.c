/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:36:58 by demilan           #+#    #+#             */
/*   Updated: 2021/04/25 13:40:40 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	div_malloc(int n)
{
	int		i;

	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = div_malloc(n);
	s = (char *)malloc((i + 1) * sizeof(char));
	if (s == 0)
		return (0);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	s[i--] = '\0';
	while (n / 10 > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	s[i--] = n % 10 + '0';
	return (s);
}
