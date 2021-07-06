/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:03:57 by demilan           #+#    #+#             */
/*   Updated: 2021/04/20 16:46:25 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	g;
	char	*s1;
	char	*str;

	if (s == NULL)
		return (0);
	s1 = (char *)s;
	i = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	g = 0;
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (0);
	while (len + start > i)
	{
		str[g] = s1[i];
		i++;
		g++;
	}
	str[g] = '\0';
	return (str);
}
