/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:44:33 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 17:55:39 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter_t	swap_t(double *t, double k)
{
	if (t[0] > t[1])
	{
		k = t[1];
		t[1] = t[0];
		t[0] = k;
	}
	return (new_intert(t[0], t[1]));
}

t_inter_t	quadratic(double a, double b, double c)
{
	double	d;
	double	k;
	double	t[2];

	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (new_intert(-1.0, -1.0));
	if (d == 0.0)
		return (new_intert(-0.5 * b / a, -0.5 * b / a));
	else
	{
		if (b > 0)
			k = -0.5 * (b + sqrt(d));
		else
			k = -0.5 * (b - sqrt(d));
		t[0] = k / a;
		t[1] = c / k;
	}
	return (swap_t(t, k));
}

double	sph_intersect(t_vec3 ro, t_vec3 rd, t_sphere *sphere)
{
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	t_inter_t	t;

	oc = vec_m_vec(ro, sphere->center);
	a = len_squared(rd);
	b = 2 * scalar_product(oc, rd);
	c = len_squared(oc) - sphere->r * sphere->r;
	t = quadratic(a, b, c);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	sphere->t = t.x - 0.0000001;
	sphere->pos = vec_p_vec(ro, mul_vec(rd, sphere->t));
	sphere->nor = normalize(vec_m_vec(sphere->pos, sphere->center));
	if (t.x == t.y)
		sphere->nor = mul_vec(sphere->nor, -1);
	return (sphere->t);
}

double	pl_intersect(t_vec3 ro, t_vec3 rd, t_plane *plane)
{
	double	d;
	double	t;

	d = -scalar_product(plane->origin, plane->normalize_vector);
	t = -(scalar_product(ro, plane->normalize_vector) + d) \
		/ scalar_product(rd, plane->normalize_vector);
	if (t >= 0)
	{
		plane->t = t;
		plane->pos = vec_p_vec(ro, mul_vec(rd, plane->t));
		if (scalar_product(plane->normalize_vector, ro) < 0)
			plane->normalize_vector = mul_vec(plane->normalize_vector, -1);
		return (t);
	}
	return (-1.0);
}

double	cy_inter(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder)
{
	double		a;
	double		b;
	double		c;
	t_inter_t	t;
	t_vec3		x[2];

	x[0] = vec_m_vec(rd, mul_vec(cylinder->n_vector, \
		scalar_product(rd, cylinder->n_vector)));
	a = scalar_product(x[0], x[0]);
	x[1] = vec_m_vec(vec_m_vec(ro, cylinder->origin), \
		mul_vec(cylinder->n_vector, scalar_product(\
			vec_m_vec(ro, cylinder->origin), cylinder->n_vector)));
	b = 2 * scalar_product(x[0], x[1]);
	c = scalar_product(x[1], x[1]) - pow((cylinder->diameter / 2), 2.0);
	t = quadratic(a, b, c);
	return (limit(t, cylinder, new_ray(ro, rd)));
}
