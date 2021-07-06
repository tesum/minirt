/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:55:41 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 20:13:06 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ft_printf.h"

t_vec3	*minus_vec(t_vec3 *vec)
{

	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
	return (vec);
}

t_vec3	castRay(t_vec3 ro, t_vec3 rd)
{
	t_vec2	it;
	t_vec3	itPos;
	t_vec3	light;
	t_vec3	color;
	double	diffuse;

	diffuse = 0;
	it = sphIntersect(ro, rd, g_scene.sphers[0].center, g_scene.sphers[0].r);
	// printf("it = %f\n", it.x);
	if (it.x > 0.0 || it.y > 0)
	{
		color = new_rgb(1, 0, 0);
	// printf("-----|%d|-----\n"), create_rgb(color);

		return (color);
	}
	
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
	return (new_rgb(255, 33, 235));
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