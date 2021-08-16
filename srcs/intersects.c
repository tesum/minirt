/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:44:33 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:17:35 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec2	quadratic(double a, double b, double c)
{
	double	d;
	double	k;
	t_vec2	t;

	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (new_vec2(-1.0, -1.0));
	if (d == 0.0)
		return (new_vec2(-0.5 * b / a, -0.5 * b / a));
	else
	{
		if (b > 0)
			k = -0.5 * (b + sqrt(d));
		else
			k = -0.5 * (b - sqrt(d));
		t.x = k / a;
		t.y = c / a;
	}
	if (t.x > t.y)
	{
		k = t.y;
		t.y = t.x;
		t.x = k;
	}
	return (t);
}

double	sph_intersect(t_vec3 ro, t_vec3 rd, t_sphere *sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	oc = vec_m_vec(ro, sphere->center);
	a = len_squared(rd);
	b = 2 * scalar_product(oc, rd);
	c = len_squared(oc) - sphere->r * sphere->r;
	d = b * b - 4 * a * c;
	if (d < 0.0)
		return (-1.0);
	d = sqrt(d);
	sphere->t = f_min((-b + d) / (2 * a), (-b - d) / (2 * a)) - 0.00001;
	sphere->pos = vec_p_vec(ro, mul_vec(rd, sphere->t));
	sphere->nor = normalize(vec_m_vec(sphere->pos, sphere->center));
	return (sphere->t);
}

double	pl_intersect(t_vec3 ro, t_vec3 rd, t_plane *plane)
{
	double	d;
	double	t;

	d = -scalar_product(plane->origin, plane->normalize_vector);
	t = -(scalar_product(ro, plane->normalize_vector) + d)
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
// 	cylinder->k0 = aoao * len_squared(cylinder->oc)
// 		- aooc * aooc - cylinder->diameter * aoao;
// }

// double cy_intersect(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder)
// {
// 	double	h;
// 	double	t;
// 	double	y;

// 	cylinder->a = vec_p_vec(cylinder->origin, 
	// mul_vec(cylinder->n_vector, cylinder->h));
// 	cylinder->c = vec_p_vec(cylinder->origin, 
	// mul_vec(cylinder->n_vector, cylinder->h / 2));
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

double	slave(t_cylinder *cy, t_vec2 t, t_ray ray, t_vec2 y)
{
	y.x = scalar_product(cy->c, cy->oc) + t.x * scalar_product(cy->c, ray.rd);
	y.y = scalar_product(cy->c, cy->oc) + t.y * scalar_product(cy->c, ray.rd);
	if (y.x > 0.0 && y.x < sqrt(len_squared(cy->ao)) * 0.5)
	{
		printf("Here1\n");
		cy->t = t.x;
		cy->pos = vec_p_vec(ray.ro, mul_vec(ray.rd, cy->t));
		cy->n_vector = normalize(vec_m_vec(vec_p_vec(cy->oc, \
			mul_vec(ray.rd, cy->t)), mul_vec(cy->c, y.x)));
		return (t.x);
	}
	if (y.y > 0.0 && y.y < sqrt(len_squared(cy->ao)) * 0.5)
	{
		printf("Here2\n");
		cy->t = t.y;
		cy->pos = vec_p_vec(ray.ro, mul_vec(ray.rd, cy->t));
		cy->n_vector = normalize(vec_m_vec(vec_p_vec(cy->oc, \
			mul_vec(ray.rd, cy->t)), mul_vec(cy->c, y.y)));
		return (t.y);
	}
	else
		return (-1.0);
	if (scalar_product(ray.rd, cy->n_vector) > 0)
		cy->n_vector = mul_vec(cy->n_vector, -1);
	return (cy->t);
}

double	cy_inter(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder)
{
	double	a;
	double	b;
	double	c;
	t_vec2	t;
	t_vec3	x;

	x = vec_m_vec(ro, cylinder->origin);
	a = len_squared(rd) - pow(scalar_product(rd, cylinder->n_vector), 2.0);
	c = len_squared(x) - pow(scalar_product(x, cylinder->n_vector), 2.0) \
		* cylinder->diameter / 2 * cylinder->diameter / 2;
	b = 2 * (scalar_product(rd, x) - scalar_product(rd, cylinder->n_vector) \
		* scalar_product(x, cylinder->n_vector));
	cylinder->a = vec_p_vec(cylinder->origin, \
		mul_vec(cylinder->n_vector, cylinder->h));
	cylinder->ao = vec_m_vec(cylinder->a, cylinder->origin);
	cylinder->c = mul_vec(cylinder->ao, 1 / sqrt(len_squared(cylinder->ao)));
	t = quadratic(a, b, c);
	if (t.x < 0)
	{
		t.x = t.y;
		if (t.x < 0)
			return (-1.0);
	}
	return (slave(cylinder, t, new_ray(ro, rd), new_vec2(0, 0)));
}
