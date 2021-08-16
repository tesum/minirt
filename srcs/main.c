/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:31:33 by demilan           #+#    #+#             */
/*   Updated: 2021/08/16 21:07:08 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_esc(int keycode, t_mlx *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx_p, img->win_p);
		exit(0);
	}
	return (0);
}

void	init_global_struct(void)
{
	g_scene.mlx.mlx_p = mlx_init();
	g_scene.mlx.color = 0;
	g_scene.width = 1920;
	g_scene.hight = 1080;
	g_scene.c_sp = 0;
	g_scene.c_pl = 0;
	g_scene.c_cy = 0;
	g_scene.req_count_obj = 0;
	g_scene.itmin = __DBL_MAX__;
}

int	main(int argc, char	**argv)
{
	int			i;
	int			j;

	init_global_struct();
	parce(argv[1]);
	j = 0;
	g_scene.mlx.win_p = mlx_new_window(g_scene.mlx.mlx_p, \
		g_scene.width, g_scene.hight, "miniRT");
	while (j < g_scene.hight)
	{
		i = 0;
		while (i < g_scene.width)
		{
			color_pixel(&g_scene.mlx,
				castRay(new_ray(g_scene.cams.origin, get_ray(i, j))));
			mlx_pixel_put(g_scene.mlx.mlx_p,
				g_scene.mlx.win_p, i, j, g_scene.mlx.color);
			i++;
		}
		j++;
	}
	mlx_hook(g_scene.mlx.win_p, 2, 1L << 0, close_esc, &g_scene.mlx);
	mlx_loop(g_scene.mlx.mlx_p);
}
