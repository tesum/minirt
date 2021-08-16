/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:22:02 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:22:04 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_cam(char *str)
{
	t_vec3	vec3;

	if (str[0] != 'C')
		return ;
	str += 1;
	g_scene.cams.origin = parse_vec3(&str);
	g_scene.cams.direction = parse_vec3(&str);
	if (vec3.x + vec3.y + vec3.z > 1.0)
		exit_error("Invalid 3d normalized vector cam", ERR_CREATE_CAM);
	g_scene.cams.FOV = ft_atoi(str);
	if (g_scene.cams.FOV < 0 && g_scene.cams.FOV > 180)
		exit_error("Invalid FOV cam", ERR_CREATE_CAM);
	new_camera();
	g_scene.req_count_obj++;
}

void	parse_light(char *str)
{
	t_vec3	vec3;

	if (str[0] != 'L')
		return ;
	str += 1;
	g_scene.lights.origin = parse_vec3(&str);
	g_scene.lights.aspect = ft_atof(&str);
	if (g_scene.lights.aspect > 1.0 && g_scene.lights.aspect < 0)
		exit_error("Invalid aspect light", ERR_CREATE_LIGHT);
	g_scene.lights.color = parse_vec3(&str);
	if ((vec3.x < 0.0 || vec3.x > 255.00000) || (vec3.y < 0.0 \
		|| vec3.y > 255.0) || (vec3.z < 0.0 || vec3.z > 255.0))
		exit_error("Invalid color light", ERR_CREATE_LIGHT);
	g_scene.req_count_obj++;
}

void	parse_sphere(char *str)
{
	t_vec3		vec3;
	t_sphere	sphere;

	if (str[0] != 's' || str[1] != 'p')
		return ;
	str += 2;
	g_scene.sphers[g_scene.c_sp].center = parse_vec3(&str);
	g_scene.sphers[g_scene.c_sp].r = ft_atof(&str);
	if (g_scene.sphers[g_scene.c_sp].r < 0.0)
		exit_error("Invalid radius sphere", ERR_CREATE_SPHERE);
	g_scene.sphers[g_scene.c_sp].color_light = parse_vec3(&str);
	vec3 = g_scene.sphers[g_scene.c_sp].color_light;
	if ((vec3.x < 0.0 || vec3.x > 255.00000) || (vec3.y < 0.0 \
		|| vec3.y > 255.0) || (vec3.z < 0.0 || vec3.z > 255.0))
		exit_error("Invalid color sphere", ERR_CREATE_SPHERE);
	g_scene.sphers[g_scene.c_sp].color_light = \
		mul_vec(g_scene.sphers[g_scene.c_sp].color_light, 1 / 255.0);
	g_scene.c_sp += 1;
}

void	parse_plane(char *str)
{
	char		**vec;
	t_vec3		vec3;

	if (str[0] != 'p' || str[1] != 'l')
		return ;
	str += 2;
	g_scene.plane[g_scene.c_pl].origin = parse_vec3(&str);
	g_scene.plane[g_scene.c_pl].normalize_vector = parse_vec3(&str);
	vec3 = g_scene.plane[g_scene.c_pl].normalize_vector;
	if (vec3.x + vec3.y + vec3.z > 1.0)
		exit_error("Invalid 3d normalized vector plane", ERR_CREATE_PLANE);
	g_scene.plane[g_scene.c_pl].color = parse_vec3(&str);
	vec3 = g_scene.plane[g_scene.c_pl].color;
	if ((vec3.x < 0.0 || vec3.x > 255.00000) || (vec3.y < 0.0 \
		|| vec3.y > 255.0) || (vec3.z < 0.0 || vec3.z > 255.0))
		exit_error("Invalid color plane", ERR_CREATE_PLANE);
	g_scene.plane[g_scene.c_pl].color = \
		mul_vec(g_scene.plane[g_scene.c_pl].color, 1 / 255.0);
	g_scene.c_pl += 1;
}

void	parse_cylinder(char *str)
{
	t_vec3		vec3;

	if (str[0] != 'c' || str[1] != 'y')
		return ;
	str += 2;
	g_scene.cylinder[g_scene.c_cy].origin = parse_vec3(&str);
	g_scene.cylinder[g_scene.c_cy].n_vector = parse_vec3(&str);
	vec3 = g_scene.cylinder[g_scene.c_cy].n_vector;
	if (vec3.x + vec3.y + vec3.z > 1.0)
		exit_error("Invalid normalized vector cylinder", ERR_CREATE_CYLINDER);
	g_scene.cylinder[g_scene.c_cy].diameter = ft_atof(&str);
	if (g_scene.cylinder[g_scene.c_cy].diameter < 0.0)
		exit_error("Invalid diameter cylinder", ERR_CREATE_CYLINDER);
	g_scene.cylinder[g_scene.c_cy].h = ft_atof(&str);
	if (g_scene.cylinder[g_scene.c_cy].h < 0.0)
		exit_error("Invalid height cylinder", ERR_CREATE_CYLINDER);
	g_scene.cylinder[g_scene.c_cy].color = parse_vec3(&str);
	vec3 = g_scene.cylinder[g_scene.c_cy].color;
	if ((vec3.x < 0.0 || vec3.x > 255.00000) || (vec3.y < 0.0 \
		|| vec3.y > 255.0) || (vec3.z < 0.0 || vec3.z > 255.0))
		exit_error("Invalid color cylinder", ERR_CREATE_CYLINDER);
	g_scene.plane[g_scene.c_pl].color = \
		mul_vec(g_scene.plane[g_scene.c_pl].color, 1 / 255.0);
	g_scene.c_cy += 1;
}
