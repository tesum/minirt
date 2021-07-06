/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:06:48 by demilan           #+#    #+#             */
/*   Updated: 2021/04/20 13:44:08 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}
