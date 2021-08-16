/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:55:41 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 20:17:35 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*minus_vec(t_vec3 *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
	return (vec);
}

void	cast_sph(t_ray ray, size_t i, t_vec3 *pos, t_vec3 *normal)
{
	double	it;
	double	itmin;

	itmin = __DBL_MAX__;
	it = sph_intersect(ray.ro, ray.rd, &g_scene.sphers[i]);
	if (it > 0.01 && it < itmin)
	{
		g_scene.mlx.rgb = g_scene.sphers[i].color_light;
		*pos = g_scene.sphers[i].pos;
		*normal = g_scene.sphers[i].nor;
		g_scene.itmin = g_scene.sphers[i].t;
	}
}

void	cast_pl(t_ray ray, size_t i, t_vec3 *pos, t_vec3 *normal)
{
	double	t;
	double	itmin;

	itmin = __DBL_MAX__;
	t = pl_intersect(ray.ro, ray.rd, &g_scene.plane[i]);
	if (t > 0.0 && t < itmin)
	{
		g_scene.mlx.rgb = g_scene.plane[i].color;
		*pos = g_scene.plane[i].pos;
		*normal = g_scene.plane[i].normalize_vector;
		g_scene.itmin = g_scene.plane[i].t;
	}
}

void	cast_cy(t_ray ray, size_t i, t_vec3 *pos, t_vec3 *normal)
{
	double	t;
	double	itmin;

	itmin = __DBL_MAX__;
	t = cy_inter(ray.ro, ray.rd, &g_scene.cylinder[i]);
	if (t > 0.0 && t < itmin)
	{
		g_scene.mlx.rgb = g_scene.cylinder[i].color;
		*pos = g_scene.cylinder[i].pos;
		*normal = g_scene.cylinder[i].n_vector;
		g_scene.itmin = g_scene.cylinder[i].t;
	}
}

t_vec3	castRay(t_ray ray)
{
	size_t	i;
	t_vec3	pos;
	t_vec3	normal;
	t_vec3	*menu;

	i = 0;
	while (i < g_scene.c_sp || i < g_scene.c_pl || i < g_scene.c_cy)
	{
		cast_sph(ray, i, &pos, &normal);
		cast_pl(ray, i, &pos, &normal);
		cast_cy(ray, i, &pos, &normal);
		i++;
	}
	if (g_scene.itmin < __DBL_MAX__ && g_scene.itmin > 0.0)
		return (mul_vec(g_scene.mlx.rgb, diffuse(pos, normal, ray.rd)));
	return (new_vec3(0, 0, 0));
}
