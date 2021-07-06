/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:44:33 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 23:37:33 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int	sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere)
// {
// 	double		a;
// 	double		b;
// 	double		c;
// 	double		discr;
// 	double		dist1;
// 	double		dist2;
// 	t_vec3		*cam_sphere;

// 	dist1 = 0;
// 	dist2 = 0;
// 	cam_sphere = vec_m_vec(cam->origin, sphere->center);
// 	a = scalar_product(ray, ray);
// 	b = 2 * (scalar_product(cam_sphere, ray));
// 	c = scalar_product(cam_sphere, cam_sphere) - (sphere->r * sphere->r);
// 	discr = b * b - 4 * a * c;
// 	free(cam_sphere);
// 	if (discr < 0)
// 		return (0);
// 	dist1 = (b * -1) - sqrt(discr) / a;
// 	dist2 = (b * -1) + sqrt(discr) / a;
// 	if (dist1 > 0)
// 		return (1);
// 	return (0);
// }
void	sph_normal(t_vec3 ro, t_vec3 rd, t_vec2 tmin, t_sphere sphers)
{
	sphers.t = f_min(tmin.x, tmin.y);
	sphers.pos = vec_p_vec(ro, mul_vec(rd, sphers.t));
	sphers.nor = normalize( \
		vec_m_vec(sphers.pos, sphers.center));
}

t_vec2 sph_intersect(t_vec3 ro, t_vec3 rd, t_sphere sphere)
{
	// printf("====== %f\n", rd.x);
	// printf("====== %f\n", rd.y);
	// printf("====== %f\n", rd.z);
	// printf("====== %f\n", ra);
	t_vec3	oc = vec_m_vec(ro, sphere.center);
	// printf("%f --- %f --- %f\n", rd.x, rd.y, rd.z);
	// printf("%f and %f and %f\n", ro->x, ro->y, ro->z);
	double a = len_squared(rd);
	double b = 2 * scalar_product(oc, rd);
	double c = scalar_product(oc, oc) - sphere.r * sphere.r;
	double d = b * b - 4 * a * c;
	// vec2 = malloc(sizeof(t_vec2));
	// if (!vec2)
	// 	er_exit(ERR_MALLOC);
	if (d < 0.0)
		return (new_vec2(-1.0, -1.0)); // no intersection

	// printf("-- %f\n", h);
	d = sqrt(d);
	sph_normal(ro, rd, new_vec2((-b - d) / (2 * a), (-b + d) / (2 * a)), sphere);
	return (new_vec2((-b - d) / (2 * a), (-b + d) / (2 * a)));
}

//  oc = vec3_sub(ro, sp->center);
//  a = vec3_dot(rd, rd);
//  b = 2 * vec3_dot(oc, rd);
//  c = vec3_dot(oc, oc) - sp->ra * sp->ra;
//  h = b * b - 4 * a * c;
//  if (h < 0.0)
//   return (new_vec2(-1.0, -1.0));
//  h = sqrt(h);
//  sp_new_normal(sp, new_vec2((-b + h) / (2 * a), (-b - h) / (2 * a)), \
//   ro, rd);
//  return (new_vec2((-b + h) / (2 * a), (-b - h) / (2 * a)));