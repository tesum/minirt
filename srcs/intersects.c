/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenijdrozdov <arsenijdrozdov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:44:33 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 09:53:54 by arsenijdroz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2 sph_intersect(t_vec3 ro, t_vec3 rd, t_sphere *sphere)
{
	t_vec3	oc;
	double a;
	double b;
	double c;
	double d;
	
	oc = vec_m_vec(ro, sphere->center);
	a = len_squared(rd);
	b = 2 * scalar_product(oc, rd);
	c = len_squared(oc) - sphere->r * sphere->r;
	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (new_vec2(-1.0, -1.0));
	d = sqrt(d);
	sphere->t = f_min((-b + d) / (2 * a), (-b - d) / (2 * a));
	sphere->pos = vec_p_vec(ro, mul_vec(rd, sphere->t));
	sphere->nor = normalize(vec_m_vec(sphere->pos, sphere->center));
	return (new_vec2((-b + d) / (2 * a), (-b - d) / (2 * a)));
}

double	pl_intersect(t_vec3 ro, t_vec3 rd, t_plane *plane)
{
	double	d;
	double	t;
	
	d = -scalar_product(plane->origin, plane->normalize_vector);
	t = -(scalar_product(ro, plane->normalize_vector) + d) / scalar_product(rd, plane->normalize_vector);
	if (t >= 0)
	{
		plane->t = t;
		plane->pos = vec_p_vec(ro, mul_vec(rd, plane->t));
		return (t);
	}
	return (-1.0);
}

// void	get_cy_k(t_cylinder *cylinder, t_vec3 rd)
// {
// 	double	aoao;
// 	double	aord;
// 	double	aooc;

// 	aoao = len_squared(cylinder->ao);
// 	aord = scalar_product(cylinder->ao, rd);
// 	aooc = scalar_product(cylinder->ao, cylinder->oc);
// 	cylinder->k2 = aoao - aord * aord;
// 	cylinder->k1 = aoao * scalar_product(cylinder->oc, rd) - aooc * aord;
// 	cylinder->k0 = aoao * len_squared(cylinder->oc) \
// 		- aooc * aooc - cylinder->diameter * aoao;
// }

// double cy_intersect(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder)
// {
// 	double	h;
// 	double	t;
// 	double	y;
	
// 	cylinder->a = vec_p_vec(cylinder->origin, mul_vec(cylinder->n_vector, cylinder->h));
// 	cylinder->c = vec_p_vec(cylinder->origin, mul_vec(cylinder->n_vector, cylinder->h / 2));
// 	cylinder->ao = vec_m_vec(cylinder->a, cylinder->origin);
// 	cylinder->oc = vec_m_vec(ro, cylinder->origin);
// 	get_cy_k(cylinder, rd);
// 	h = cylinder->k1 * cylinder->k1 - cylinder->k2  * cylinder->k0;
// 	if (h < 0.0)
// 		return (-1.0);
// 	h = sqrt(h);
// 	t = (-cylinder->k1 - h) / cylinder->k2;
// 		return (0);
// }

t_vec2 cy_inter(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder)
{
	double	a;
	double	b;
	double	d;
	double	c;
	t_vec2	t;
	t_vec3	x;
	
	x = vec_m_vec(ro, cylinder->origin);
	a = len_squared(rd) - scalar_product(rd, cylinder->n_vector) * scalar_product(rd, cylinder->n_vector);
	c = len_squared(x) - scalar_product(x, cylinder->n_vector) * scalar_product(x, cylinder->n_vector) * cylinder->diameter / 2 * cylinder->diameter / 2;
	b = 2 * (scalar_product(rd, x) - scalar_product(rd, cylinder->n_vector) * scalar_product(x, cylinder->n_vector));
	d = sqrt(pow(b, 2) - 4 * a * c);
	t = new_vec2((-b + d) / 2 * a, (-b - d) / 2 * a);
// 	y = scalar_product(cylinder->ao, cylinder->oc) + t * scalar_product(cylinder->ao, rd);
// 	if (y > 0.0 &&  y < len_squared(cylinder->ao))
	if (t.x > 0.1 || t.y > 0.1)
	{
		cylinder->t = f_min(t.x, t.y);
		cylinder->pos = vec_p_vec(ro, mul_vec(rd, cylinder->t));
		return (t);
	}
	return (new_vec2(-1.0, -1.0));
}
