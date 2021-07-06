/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:52:23 by demilan           #+#    #+#             */
/*   Updated: 2021/07/04 18:30:04 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	check_n(char **line, char **str)
{
	char	*tmp;
	char	*reserv;

	reserv = *str;
	tmp = ft_strchr(*str, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*str);
		if (!(*line))
		{
			free(*line);
			return (-1);
		}
		*str = ft_strdup(tmp + 1);
		if (!(*str))
		{
			free(*str);
			return (-1);
		}
		free(reserv);
		return (1);
	}
	return (0);
}

static int	cs(char *target)
{
	free(target);
	return (1);
}

static int	readfile(int fd, char **str, char **line, char *buf)
{
	int		i;

	i = read(fd, buf, BUFFER_SIZE);
	while (i)
	{
		buf[i] = '\0';
		*str = ft_strjoin_gnl(*str, buf);
		if (!*str)
			return (-1);
		if (check_n(line, &(*str)) == 1)
			return (cs(buf));
		else if (check_n(line, &(*str)) == -1)
			return (-1);
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (check_n(line, &(*str)) == 1)
		return (1);
	*line = ft_strdup(*str);
	if (!(*line))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			i;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || (read(fd, 0, 0) < 0))
		return (-1);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return (-1);
	}
	i = readfile(fd, &str, line, buf);
	return (i);
}
