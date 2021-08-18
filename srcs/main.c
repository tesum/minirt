/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:31:33 by demilan           #+#    #+#             */
/*   Updated: 2021/08/19 00:43:28 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
}

void	rendering(void)
{
	int			i;
	int			j;

	j = 0;
	g_scene.mlx.win_p = mlx_new_window(g_scene.mlx.mlx_p, \
		g_scene.width, g_scene.hight, "miniRT");
	while (j < g_scene.hight)
	{
		i = 0;
		while (i < g_scene.width)
		{
			color_pixel(&g_scene.mlx, \
				castRay(new_ray(g_scene.cams.origin, \
					get_ray(i, j, g_scene.cams))));
			mlx_pixel_put(g_scene.mlx.mlx_p,
				g_scene.mlx.win_p, i, j, g_scene.mlx.color);
			i++;
		}
		j++;
	}
}

int	main(int argc, char	**argv)
{
	if (argc != 2)
		exit_error("Invalid count argument", ERR_ARGUMENT);
	init_global_struct();
	parce(argv[1]);
	rendering();
	mlx_hook(g_scene.mlx.win_p, 2, 1L << 0, close_esc, &g_scene.mlx);
	mlx_hook(g_scene.mlx.win_p, 17, 1L << 0, destroy, &g_scene.mlx);
	mlx_loop(g_scene.mlx.mlx_p);
}
