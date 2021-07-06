/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:02:24 by demilan           #+#    #+#             */
/*   Updated: 2021/04/18 19:12:40 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		c1;

	i = 0;
	str = (unsigned char *)s;
	c1 = c;
	while (n > i)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (0);
}
