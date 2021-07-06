/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:01:38 by demilan           #+#    #+#             */
/*   Updated: 2021/04/18 19:12:12 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*str;
	void			*result;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	str = (unsigned char *)result;
	i = 0;
	while (i < count * size)
	{
		*(str + i) = 0;
		i++;
	}
	return (result);
}
