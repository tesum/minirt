/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:21:54 by demilan           #+#    #+#             */
/*   Updated: 2021/08/19 00:47:48 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	shadow(t_vec3 ro, t_vec3 rd)
{
	double	it;
	int		i;
	double	tmin;

	i = 0;
	tmin = 1.0;
	while (i < g_scene.c_sp || i < g_scene.c_pl || i < g_scene.c_cy)
	{
		it = sph_intersect(ro, rd, &g_scene.sphers[i]);
		if (it > 0.001 && it < tmin)
			tmin = it;
		it = pl_intersect(ro, rd, &g_scene.plane[i]);
		if (it > 0.001 && it < tmin)
			tmin = it;
		it = cy_inter(ro, rd, &g_scene.cylinder[i]);
		if (it > 0.0 && it < tmin)
			tmin = it;
		i++;
	}
	if (tmin < 1.0)
		return (1);
	return (0);
}

double	phongs_model(double power, t_vec3 l_dir, t_vec3	rd, t_vec3 normal)
{
	t_vec3	r;
	double	res;

	res = power;
	r = vec_m_vec(mul_vec(mul_vec(normal, 2), \
		scalar_product(normal, l_dir)), l_dir);
	rd = mul_vec(rd, -1);
	res += pow(f_max(scalar_product(r, rd) / (sqrt(len_squared(r)) * \
		sqrt(len_squared(rd))), 0.0), 256.0) * g_scene.lights.aspect;
	return (res);
}

double	diffuse(t_vec3 pos, t_vec3 normal, t_vec3 rd)
{
	t_vec3	light_dir;
	double	dot_light;
	double	power;

	power = g_scene.alight.aspect;
	light_dir = vec_m_vec(g_scene.lights.origin, pos);
	dot_light = scalar_product(normal, light_dir);
	if (dot_light > 0.0)
	{
		if (shadow(pos, light_dir) == 1)
			return (f_min(power, 1.0));
	}
	power += (f_max(dot_light, 0.0) * g_scene.lights.aspect) / \
		(sqrt(len_squared(normal)) * sqrt(len_squared(light_dir)));
	return (f_min(phongs_model(power, light_dir, rd, normal), 1.0));
}
