/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:58:03 by demilan           #+#    #+#             */
/*   Updated: 2021/04/18 17:57:45 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*d;

	c = (unsigned char)c;
	d = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		d[i] = sr[i];
		if (sr[i] == c)
			return (d + ++i);
		i++;
	}
	return (0);
}
