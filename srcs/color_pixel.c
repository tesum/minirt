/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:28:28 by demilan           #+#    #+#             */
/*   Updated: 2021/08/19 00:45:34 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	mul_vec(t_vec3 vec, double k)
{
	t_vec3	res;

	res.x = vec.x * k;
	res.y = vec.y * k;
	res.z = vec.z * k;
	return (res);
}

t_vec3	*minus_vec(t_vec3 *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
	return (vec);
}

void	color_pixel(t_mlx *mlx, t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	mlx->rgb.x = r * 256 * 256;
	mlx->rgb.y = g * 256;
	mlx->rgb.z = b;
	mlx->color = mlx->rgb.x + mlx->rgb.y + mlx->rgb.z;
}

void	new_camera(void)
{
	double		ratio;
	double		vp_h;
	double		vp_w;
	t_vec3		vup;

	vup = new_vec3(0.0, 1.0, 0.0);
	ratio = 16.0 / 9.0;
	vp_h = tan((((double)g_scene.cams.FOV) * M_PI / 180) / 2.0);
	vp_w = ratio * vp_h;
	g_scene.cams.w = normalize(\
		vec_m_vec(g_scene.cams.origin, g_scene.cams.direction));
	g_scene.cams.u = normalize(cross(vup, g_scene.cams.w));
	g_scene.cams.v = cross(g_scene.cams.w, g_scene.cams.u);
	g_scene.cams.horizontal = mul_vec(g_scene.cams.u, vp_w * 2);
	g_scene.cams.vertical = mul_vec(g_scene.cams.v, vp_h * 2);
	g_scene.cams.l_left_corner = vec_m_vec(vec_m_vec(\
		vec_m_vec(g_scene.cams.origin, mul_vec(g_scene.cams.u, vp_w)), \
		mul_vec(g_scene.cams.v, vp_h)), g_scene.cams.w);
}
