/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:56:29 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 17:53:34 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_inter_t	new_intert(double x, double y)
{
	t_inter_t	new;

	new.x = x;
	new.y = y;
	return (new);
}

double	solve(double t, t_cylinder *cy, t_ray ray)
{
	t_vec3	m;

	cy->t = t - 0.0001;
	cy->pos = vec_p_vec(ray.ro, mul_vec(ray.rd, cy->t));
	m = vec_m_vec(cy->pos, cy->origin);
	cy->normal = normalize(vec_m_vec(m, \
		mul_vec(cy->n_vector, scalar_product(cy->n_vector, m))));
	if (scalar_product(ray.rd, cy->normal) > 0)
		cy->normal = mul_vec(cy->normal, -1);
	return (t);
}

double	limit(t_inter_t t, t_cylinder *cy, t_ray ray)
{
	t_vec3	b;
	t_vec3	a;

	a = vec_p_vec(cy->origin, mul_vec(cy->n_vector, cy->h));
	if (t.x > 0)
	{
		b = vec_p_vec(ray.ro, mul_vec(ray.rd, t.x));
		if (scalar_product(cy->n_vector, vec_m_vec(b, cy->origin)) > 0)
		{
			if (scalar_product(cy->n_vector, vec_m_vec(b, a)) < 0)
				return (solve(t.x, cy, ray));
		}
	}
	if (t.y > 0)
	{
		b = vec_p_vec(ray.ro, mul_vec(ray.rd, t.y));
		if (scalar_product(cy->n_vector, vec_m_vec(b, cy->origin)) > 0)
		{
			if (scalar_product(cy->n_vector, vec_m_vec(b, a)) < 0)
				return (solve(t.y, cy, ray));
		}
	}
	return (-1);
}
