/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:28:28 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 18:01:36 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	mul_vec(t_vec3 vec, double k)
{
	t_vec3	res;
	// printf("--- %f --- %f --- %f \n", vec->x, vec->y, vec->z);

	res.x = vec.x * k;
	res.y = vec.y * k;
	res.z = vec.z * k;
	// printf("--- %f --- %f --- %f \n", res->x, res->y, res->z);
	return (res);
}

t_vec2	get_pixel(t_vec2 resolution, int mlx_x, int mlx_y)
{
	t_vec2	pixel;

	pixel.x = ((2 * mlx_x) - resolution.x) / resolution.y;
	pixel.y = ((2 * mlx_y) - resolution.x) / resolution.y;
	return (pixel);
}

void	color_pixel(t_mlx *mlx_s, t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = color.x * 255.999;
	g = color.y * 255.999;
	b = color.z * 255.999;
	
	mlx_s->rgb.x = r * 256 * 256;
	mlx_s->rgb.y = g * 256;
	mlx_s->rgb.z = b;
	// printf("r: %f  | g: %f  | b: %f\n", mlx_s->rgb.x, mlx_s->rgb.y, mlx_s->rgb.z);
	mlx_s->color = mlx_s->rgb.x + mlx_s->rgb.y + mlx_s->rgb.z;
	// printf("color: %d\n", mlx_s->color);
}

int	create_rgb(t_vec3 *rgb)
{
	int	t;
	int r;
	int g;
	int b;

	t = 1;
	r = rgb->x;
	g = rgb->x;
	b = rgb->z;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_vec3	new_rgb(int r, int g, int b)
{
	t_vec3	color;
	
	// color = malloc(sizeof(t_rgb));
	// if (!color)
	// 	er_exit(ERR_MALLOC);
	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}
