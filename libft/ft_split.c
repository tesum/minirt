/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:53:35 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 11:33:07 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	elements(const char *s, char c)
{
	size_t	i;
	int		elem;
	int		isseparator;

	isseparator = 1;
	elem = 0;
	i = 0;
	while (s[i])
	{
		if (isseparator == 1)
		{
			if (s[i] != c)
			{
				elem++;
				isseparator = 0;
			}
		}
		else if (s[i] == c)
			isseparator = 1;
		i++;
	}
	return (elem);
}

static	int	len_sub(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static	void	cs(int elem, char **str)
{
	while (elem >= 0)
	{
		free(str[elem]);
		str[elem] = NULL;
		elem--;
	}
	str = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		elem;
	int		elem_max;
	char	**str;

	if (s == NULL)
		return (NULL);
	elem_max = elements(s, c);
	str = (char **)malloc((elem_max + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	elem = 0;
	while (elem < elem_max)
	{
		while (s[i] == c)
			i++;
		str[elem] = ft_substr(s, i, len_sub(s, c, i));
		if (!str[elem])
			cs(elem - 1, str);
		elem++;
		i += len_sub(s, c, i);
	}
	str[elem] = NULL;
	return (str);
}
