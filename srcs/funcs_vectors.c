/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:13:06 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:19:06 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec_p_vec(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res = new_vec3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	return (res);
}

t_vec3	vec_m_vec(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res = new_vec3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (res);
}

double	scalar_product(t_vec3 vec1, t_vec3 vec2)
{
	double	res;

	res = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	return (res);
}

t_vec3	vec_div(t_vec3 vec, double k)
{
	t_vec3	new;

	new.x = vec.x / k;
	new.y = vec.y / k;
	new.z = vec.z / k;
	return (new);
}

t_vec3	normalize(t_vec3 vec)
{
	float	len;

	len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vec.x *= 1 / len;
	vec.y *= 1 / len;
	vec.z *= 1 / len;
	return (vec);
}
