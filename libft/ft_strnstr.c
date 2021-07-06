/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:27:08 by demilan           #+#    #+#             */
/*   Updated: 2021/04/22 12:37:25 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	i = 0;
	if (haystack == NULL && len == 0)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			{
				if (i + ft_strlen(needle) <= len)
					return ((char *)haystack + i);
				else
					return (0);
			}
		}
		i++;
	}
	return (NULL);
}
