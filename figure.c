/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:56:29 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 18:00:30 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	new;

	// new = malloc(sizeof(t_vec3));
	// if (!new)
	// 	er_exit(ERR_MALLOC);
	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec2	new_vec2(double x, double y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_sphere	new_sphere(t_vec3 center, double r, t_vec3 color)
{
	t_sphere	sphere;

	// sphere = malloc(sizeof(t_sphere));
	// if (!sphere)
	// 	er_exit(ERR_MALLOC);
	sphere.center = center;
	sphere.r = r;
	sphere.color_light = color;
	return (sphere);
}
