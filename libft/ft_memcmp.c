/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:20:02 by demilan           #+#    #+#             */
/*   Updated: 2021/04/18 19:13:27 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11;
	const unsigned char	*s22;
	size_t				i;

	s11 = s1;
	s22 = s2;
	i = 0;
	while (n > i)
	{
		if (s11[i] == s22[i])
			i++;
		else if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
	}
	return (0);
}
