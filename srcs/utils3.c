/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:21:59 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:22:00 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	new.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	new.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (new);
}

double	len_squared(t_vec3 vec3)
{
	return (vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
}

t_vec3	vec_mul_vec(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x * vec2.x;
	vec.y = vec1.y * vec2.y;
	vec.z = vec1.z * vec2.z;
	return (vec);
}

t_vec3	get_ray(double i, double j)
{
	t_camera	cam;
	t_vec3		ray;
	t_vec2		uv;

	uv.x = (double)i / (g_scene.width - 1);
	uv.y = (g_scene.hight - (double)j - 1) / (g_scene.hight - 1);
	cam = g_scene.cams;
	ray = vec_p_vec(cam.l_left_corner, \
		vec_p_vec(mul_vec(cam.horizontal, uv.x), \
		vec_m_vec(mul_vec(cam.vertical, uv.y), cam.origin)));
	return (normalize(ray));
}

t_ray	new_ray(t_vec3 ro, t_vec3 rd)
{
	t_ray	ray;

	ray.ro = ro;
	ray.rd = rd;
	return (ray);
}
