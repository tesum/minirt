/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenijdrozdov <arsenijdrozdov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:55:41 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 09:56:23 by arsenijdroz      ###   ########.fr       */
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

double	cast_sph(t_vec3 *menu, size_t i, t_vec3 *pos, t_vec3 *normal)
{
	t_vec2	it;
	double itmin;
	
	itmin = __DBL_MAX__;
	it = sph_intersect(menu[0], menu[1], &g_scene.sphers[i]);
	if (it.x > 0.01 && it.x < itmin)
	{
		g_scene.mlx.rgb = g_scene.sphers[i].color_light;
		*pos = g_scene.sphers[i].pos;
		*normal = g_scene.sphers[i].nor;
		itmin = g_scene.sphers[i].t;
	}
	return (itmin);
}

double cast_pl(t_vec3 *menu, size_t i, t_vec3 *pos, t_vec3 *normal)
{
	double	t;
	double	itmin;
	
	itmin = __DBL_MAX__;
	t = pl_intersect(menu[0], menu[1], &g_scene.plane[i]);
	if (t > 0.0 && t < itmin)
	{
		g_scene.mlx.rgb = g_scene.plane[i].color;
		*pos = g_scene.plane[i].pos;
		*normal = g_scene.plane[i].normalize_vector;
		itmin = g_scene.plane[i].t;
	}
	return (itmin);
}

double cast_cy(t_vec3 *menu, size_t i)
{
	t_vec2	t;
	double	itmin;
	
	itmin = __DBL_MAX__;
	t = cy_inter(menu[0], menu[1], &g_scene.cylinder[i]);
	if (t.x > 0.0 && t.x < itmin)
	{
		g_scene.mlx.rgb = g_scene.cylinder[i].color;
		menu[2] = g_scene.cylinder[i].pos;
		menu[3] = g_scene.cylinder[i].n_vector;
		itmin = g_scene.cylinder[i].t;
	}
	return (itmin);
}

t_vec3	castRay(t_vec3 ro, t_vec3 rd)
{
	size_t	i;
	t_vec3	pos;
	t_vec3	normal;
	t_vec3	*menu;
	double	itmin;
	
	menu = malloc(sizeof(t_vec3) * 4);
	menu[0] = ro;
	menu[1] = rd;
	menu[2] = pos;
	menu[3] = normal;
	itmin = __DBL_MAX__;
	i = 0;
	while (i < g_scene.c_sp || i < g_scene.c_pl || i < g_scene.c_cy)
	{
		itmin = cast_sph(menu, i, &pos, &normal);
		// pos = menu[2];
		// normal = menu[3];
		if (itmin < __DBL_MAX__)
		{
			free(menu);// не правильный подход чистить меню надо по всем фигурам пройтись и найти минимал в этой точке потом чистить
			return (mul_vec(g_scene.mlx.rgb, diffuse(pos, normal, rd)));
		}
		itmin = cast_pl(menu, i, &pos, &normal);
		// pos = menu[2];
		// normal = menu[3];
		if (itmin < __DBL_MAX__)
		{
			free(menu);
			return (mul_vec(g_scene.mlx.rgb, diffuse(pos, normal, rd)));
		}
		itmin = cast_cy(menu, i);
		pos = menu[2];
		normal = menu[3];
		if (itmin < __DBL_MAX__)
		{
			free(menu);
			return (mul_vec(g_scene.mlx.rgb, diffuse(pos, normal, rd)));
		}
		i++;
	}
	return (new_vec3(0,0,0));
	// printf("it = %f\n", it.x);
	
		// return (sp->color_light);
		
	// itPos = mul_vec(vec_p_vec(ro, rd), it.x);
	// itPos = normalize(vec_m_vec(vec_p_vec(ro, mul_vec(rd, it.x)), g_scene.sphers[0].center));
	// light = normalize(g_scene.lights.origin);
	// // printf("--- %f --- %f --- %f \n", itPos->x, itPos->z, itPos->z);
	// // printf("--- %f --- %f --- %f \n", light->x, light->y, light->z);
	// // printf("----\n");
	// diffuse = scalar_product(mul_vec(light, 0.8), itPos);
	// printf("---- %f\n", it->x);
	// printf("---\n");
	// color->r = diffuse;
	// color->g = 0;
	// color->b = 0;
	// printf("    - -- - %f\n", diffuse + sp->color_light);
	// return (mul_vec(g_scene.sphers[0].color_light, diffuse * 0.04));
	// return (sp->color_light);
	// return (create_rgb(color) + sp->color_light);
	// return (diffuse);
	return (new_vec3(1, 1, 1));
}

// double	sphSoftShadow(t_vec3 *ro, t_vec3 *rd, t_vec3 *ce, double ra)
// {
// 	double	diffuse;
// 	double	t;
	
// 	t_vec3	*oc = vec_m_vec(ro, ce);
// 	double b = scalar_product(oc, rd);
// 	double c = scalar_product(oc, oc) - ra * ra;
// 	double h = b * b - c;
// 	diffuse = sqrt(f_max(0.0, ra)) - ra;
// 	t = -b - sqrt(f_max(h, 0.0));
// 	if (t < 0.0)
// 		return (1);
// 	else
// 		return (smoothstep(0.0, 1.0, 2 * diffuse / t));
// }