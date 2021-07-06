/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:32:05 by demilan           #+#    #+#             */
/*   Updated: 2021/04/22 17:47:02 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charstr_bonus(const char s1, const char *s2)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s2[i] != '\0')
	{
		if (s1 == s2[i])
			res++;
		i++;
	}
	if (res > 0)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_charstr_bonus(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_charstr_bonus(s1[j - 1], set) == 1)
		j--;
	str = ft_substr(s1, i, j - i);
	if (str == 0)
		return (0);
	return (str);
}
