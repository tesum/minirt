/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:41:54 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 17:10:11 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_alight(char *str)
{
	t_vec3	vec3;

	if (str[0] != 'A')
		return ;
	str += 1;
	g_scene.alight.aspect = ft_atof(&str);
	if (g_scene.alight.aspect > 1.0 || g_scene.alight.aspect < 0)
		exit_error("Invalid aspect alight", ERR_CREATE_ALIGHT);
	g_scene.alight.color = parse_vec3(&str);
	vec3 = g_scene.alight.color;
	if ((vec3.x < 0.0 || vec3.x > 255.00000) || (vec3.y < 0.0 \
		|| vec3.y > 255.0) || (vec3.z < 0.0 || vec3.z > 255.0))
		exit_error("Invalid color alight", ERR_CREATE_ALIGHT);
	g_scene.req_count_obj++;
}

void	check_map_name(char *map)
{
	while (*map && *map != '.')
		map += 1;
	if (*map == '\n')
		exit_error("Invalid scene name", ERR_MAP);
	map += 1;
	if (*map != 'r' || *(map + 1) != 't')
		exit_error("Invalid scene name", ERR_MAP);
}

void	not_object(char *str)
{
	if (str[0] != '\0' && str[0] != '\n')
	{
		if (str[0] != 'A' && str[0] != 'C' && str[0] != 'L' \
			&& (str[0] != 's' || str[1] != 'p') \
			&& (str[0] != 'p' || str[1] != 'l') \
			&& (str[0] != 'c' || str[1] != 'y'))
			exit_error("Invalid scene object", ERR_SCENE_OBJ);
	}
}

void	parce(char *map)
{
	int		fd;
	int		k;
	char	*line;
	char	**split_line;

	check_map_name(map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_error("Invalid open map", ERR_MAP);
	k = 1;
	while (k > 0)
	{
		k = get_next_line(fd, &line);
		parse_alight(line);
		parse_cam(line);
		parse_light(line);
		parse_sphere(line);
		parse_plane(line);
		parse_cylinder(line);
		not_object(line);
		free(line);
		line = NULL;
	}
	if (g_scene.req_count_obj != 3)
		exit_error("Required objects error", ERR_REQ_OBJECT);
}
