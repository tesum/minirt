/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:22:58 by demilan           #+#    #+#             */
/*   Updated: 2021/04/19 22:09:53 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*sr;
	char		*d;

	d = (char *)dst;
	sr = (char *)src;
	i = 0;
	if (d > sr)
	{
		while (len-- > 0)
		{
			d[len] = sr[len];
		}
	}
	else if (d < sr)
	{
		while (len > i)
		{
			*(d + i) = *(sr + i);
			i++;
		}
	}
	else
		return (d);
	return (d);
}
