/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:36:16 by demilan           #+#    #+#             */
/*   Updated: 2021/04/19 23:25:52 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		g;

	i = 0;
	g = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[g] != '\0' && dstsize > (i + g + 1))
	{
		dst[i + g] = src[g];
		g++;
	}
	if (i < dstsize)
		dst[i + g] = '\0';
	return (ft_strlen(src) + i);
}
