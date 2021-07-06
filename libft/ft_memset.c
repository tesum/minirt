/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:17:24 by demilan           #+#    #+#             */
/*   Updated: 2021/04/18 19:11:42 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c1;

	str = (unsigned char *)b;
	c1 = (unsigned char )c;
	i = 0;
	while (i < len)
	{
		*(str + i) = c1;
		i++;
	}
	return (b);
}
