/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:00:24 by demilan           #+#    #+#             */
/*   Updated: 2021/07/04 18:29:55 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		d[i] = sr[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		len_str;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len_str + 1));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[len_str] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
