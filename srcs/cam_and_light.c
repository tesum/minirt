/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_and_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:02:35 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:09:48 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	new_light(t_vec3 origin, double aspect, t_vec3 color)
{
	t_light	light;

	light.origin = origin;
	light.aspect = aspect;
	light.color = color;
	return (light);
}

void	new_camera(void)
{
	double		ratio;
	double		vp_h;
	double		vp_w;
	double		len;
	t_vec3		vup;

	vup = new_vec3(0.0, 1.0, 0.0);
	ratio = 16.0 / 9.0;
	vp_h = tan(((double)g_scene.cams.FOV) / 2.0);
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
