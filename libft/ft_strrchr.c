/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:49:22 by demilan           #+#    #+#             */
/*   Updated: 2021/04/19 21:55:29 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		i;
	int		lol;

	s2 = (char *)s;
	i = 0;
	lol = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] == c)
			lol = i;
		i++;
	}
	if (s2[i] == c)
		return ((char *)s + i);
	if (s2[lol] == c)
		return ((char *)s + lol);
	else
		return (0);
}
