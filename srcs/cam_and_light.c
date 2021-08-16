/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_and_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenijdrozdov <arsenijdrozdov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:02:35 by demilan           #+#    #+#             */
/*   Updated: 2021/08/06 16:20:24 by arsenijdroz      ###   ########.fr       */
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
	double			vp_h;
	double			vp_w;
	double			ratio;
	double		len;
	t_vec3		vup;
	
	vup = new_vec3(0.0, 1.0, 0.0);
	ratio = 16.0 / 9.0;
	vp_h = tan(((double)g_scene.cams.FOV) / 2.0);
	vp_w = ratio * vp_h;
	printf("========= %f\n", g_scene.cams.origin.x);
	printf("========= %f\n", g_scene.cams.origin.y);
	printf("========= %f\n", g_scene.cams.origin.z);
	printf("========= %f\n", g_scene.cams.direction.x);
	printf("========= %f\n", g_scene.cams.direction.y);
	printf("========= %f\n", g_scene.cams.direction.z);
	printf("========= %f\n", vp_h);
	// printf("========= %f\n", ratio);
	printf("========= %f\n", vp_w);
	// g_scene.cams.w = normalize(vec_m_vec(g_scene.cams.origin, g_scene.cams.direction));
	g_scene.cams.w = normalize(vec_m_vec(g_scene.cams.origin, g_scene.cams.direction));
	g_scene.cams.u = normalize(cross(vup, g_scene.cams.w));
	g_scene.cams.v = cross(g_scene.cams.w, g_scene.cams.u);
	g_scene.cams.horizontal = mul_vec(g_scene.cams.u, vp_w * 2);
	g_scene.cams.vertical = mul_vec(g_scene.cams.v, vp_h * 2);
	g_scene.cams.l_left_corner = vec_m_vec(vec_m_vec(vec_m_vec(g_scene.cams.origin, mul_vec(g_scene.cams.u, vp_w)), mul_vec(g_scene.cams.v, vp_h)), g_scene.cams.w);
	printf("========= %f\n", g_scene.cams.w.x);
	printf("========= %f\n", g_scene.cams.w.y);
	printf("========= %f\n", g_scene.cams.w.z);
	printf("========= %f\n", g_scene.cams.u.x);
	printf("========= %f\n", g_scene.cams.u.y);
	printf("========= %f\n", g_scene.cams.u.z);
	printf("========= %f\n", g_scene.cams.v.x);
	printf("========= %f\n", g_scene.cams.v.y);
	printf("========= %f\n", g_scene.cams.v.z);
	// g_scene.cams.l_left_corner = vec_m_vec(g_scene.cams.origin, vec_m_vec(vec_m_vec(vec_div(g_scene.cams.horizontal, 2), vec_div(g_scene.cams.vertical, 2)), g_scene.cams.w));
}

// t_scene	*new_scene(t_camera *cam, t_sphere *sphere)
// {
// 	t_scene	*scene;

// 	scene = malloc(sizeof(t_scene));
// 	if (!scene)
// 		er_exit();
// 	scene->width = 0;
// 	scene->hight = 0;
// 	scene->sphers = sphere;
// 	scene->cams = cam;
// 	return (scene);
// }
