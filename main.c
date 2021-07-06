/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:31:33 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 20:09:32 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "./gnl/get_next_line.h"


int	close_esc(int keycode, t_mlx *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx_p, img->win_p);
		exit(0);
	}
	return (0);
}
void	init_global_struct()
{
	g_scene.width = 1920;
	g_scene.hight = 1080;
	g_scene.c_sp = 0;
	g_scene.c_pl = 0;
	g_scene.c_cy = 0;
	g_scene.req_count_obj = 0;
}

int	main(int argc, char	**argv)
{
	t_mlx		*mlx_s;
	t_vec2		uv;
	t_vec3		rayOrigin;
	t_vec3		rayDirection;
	t_vec3		col;

	mlx_s = malloc(sizeof(t_mlx));
	mlx_s->mlx_p = mlx_init();
	init_global_struct();
	parce(argv[1]);
	printf("A aspect = %.5f  | color.x = %f\n", g_scene.alight.aspect, g_scene.alight.color.x);
	printf("C origin.x = %.5f  |  direction.x = %f  |  FOV = %d\n", g_scene.cams.origin.x, g_scene.cams.direction.x, g_scene.cams.FOV);
	printf("%f ========= %f ========== %f\n", g_scene.cams.direction.x, g_scene.cams.direction.y, g_scene.cams.direction.z);
	printf("L origin.x = %.5f  |  aspect = %f  | color.x = %f\n", g_scene.lights.origin.x, g_scene.lights.aspect, g_scene.lights.color.x);
	printf("sp origin.x = %.5f  |  r = %f  | color.x = %f\n", g_scene.sphers[0].center.x, g_scene.sphers[0].r, g_scene.sphers[0].color_light.x);
	printf("cy origin.x = %.5f  |  vec = %f\n", g_scene.cylinder[0].origin.x, g_scene.cylinder[0].normalize_vector.x);
	printf("pl origin.x = %.5f  |  normileze = %f  |  color.x = %f\n", g_scene.plane[0].origin.x, g_scene.plane[0].normalize_vector.x, g_scene.plane[0].color.x);
	printf("count obj = %d\n", g_scene.req_count_obj);
	printf("cam h.x = %f  |  v.x = %f  |  l.x = %f\n", g_scene.cams.horizontal.x, g_scene.cams.vertical.x, g_scene.cams.l_left_corner.x);
	// exit(1);
	// g_scene.sphers = new_sphere(new_vec3(1, 1, -6), 1, new_rgb(180, 55, 55));
	// g_scene.lights = new_light(new_vec3(6, 4, -1), 0.9, new_rgb(255, 255,255));
	// g_scene.cams = new_camera(new_vec3(0, 0, 0), new_vec3(0, 0, -1), 80);

	mlx_s->win_p = mlx_new_window(mlx_s->mlx_p, g_scene.width, g_scene.hight, "LoL");
	mlx_s->mlx_x = 0;
	mlx_s->color = 0;
	while (mlx_s->mlx_x <= g_scene.width)
	{
		mlx_s->mlx_y = 0;
		while(mlx_s->mlx_y <= g_scene.hight)
		{
			uv.x = (double)mlx_s->mlx_y / (g_scene.width - 1);
			uv.y = (g_scene.hight - (double)mlx_s->mlx_x - 1) / (g_scene.hight - 1);
			// ray.x = g_scene.cams.origin;
			rayOrigin = g_scene.cams.origin;
			// rayDirection = normalize(new_vec3(1, uv.x, uv.y));
			rayDirection = get_ray(uv.x, uv.y);
			
			// normalize(rayDirection);
			// printf("%f --- %f --- %f\n", rayDirection.x, rayDirection.y, rayDirection.z);
			col = castRay(rayOrigin, rayDirection);
			color_pixel(mlx_s, col);
				// printf("HERE NO CRUSH  |  x: %d   y: %d  col: %d\n", mlx_s->mlx_x, mlx_s->mlx_y, mlx_s->color);
			// printf("%10d\n", create_rgb(col));
			mlx_pixel_put(mlx_s->mlx_p, mlx_s->win_p, mlx_s->mlx_x, mlx_s->mlx_y, mlx_s->color);
			mlx_s->mlx_y++;
		}
		mlx_s->mlx_x++;
	}
	mlx_hook(mlx_s->win_p, 2, 1L<<0, close_esc, &mlx_s);
	mlx_loop(mlx_s->mlx_p);
}
//  t_cam cam;
//  t_vec3 ray;
//  double u;
//  double v;

//  u = (double)i / (g_scene.width - 1);
//  v = (g_scene.height - (double)j - 1) / (g_scene.height - 1);
//  cam = g_scene.cam;
//  ray = vec3_add(cam.lower_left_corner,
//    vec3_add(vec3_mulS(cam.horizontal, u),
//     vec3_sub(vec3_mulS(cam.vertical, v), cam.ro)));
//  return (vec3_norm(ray));
