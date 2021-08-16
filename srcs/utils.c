#include "miniRT.h"

int	shadow(t_vec3 ro, t_vec3 rd)
{
	t_vec2	it;
	int		i;
	double	tmin;

	i = 0;
	tmin = 1.0;
	while (i < g_scene.c_sp || i < g_scene.c_pl || i < g_scene.c_cy)
	{
		it = sph_intersect(ro, rd, &g_scene.sphers[i]);
		if (it.x > 0.001 || it.y > 0.001)
			tmin = f_min(it.x, it.y);
		it.x = pl_intersect(ro, rd, &g_scene.plane[i]);
		if (it.x > 0.1 || it.x < tmin)
			tmin = it.x;
		// it = cy_inter(ro, rd, &g_scene.cylinder[i]); // глушит весь свет
		// if (it.x > 0.1 || it.x < tmin)
		// 	tmin = it.x;
		i++;
	}
	if (tmin < 1.0)
		return (1);
	return (0);
}

double	diffuse(t_vec3 pos, t_vec3 normal, t_vec3 rd)
{
	t_vec3	light_dir;
	t_vec3	r;
	double	dot_light;
	double	power;

	power = g_scene.alight.aspect;
	light_dir = vec_m_vec(g_scene.lights.origin, pos);
	dot_light = scalar_product(normal, light_dir);
	if (dot_light > 0.0)
	{
		if (shadow(pos, light_dir) == 1)
			return (f_min(power, 1.0));
	}

	power += (f_max(dot_light, 0.0) * g_scene.lights.aspect) / (sqrt(len_squared(normal)) * sqrt(len_squared(light_dir)));

	r = vec_m_vec(mul_vec(mul_vec(normal, 2), scalar_product(normal, light_dir)), light_dir);
	rd = mul_vec(rd, -1);
	power += pow(f_max(scalar_product(r, rd) / (sqrt(len_squared(r)) * sqrt(len_squared(rd))), 0.0), 256.0) * g_scene.lights.aspect;
	return (f_min(power, 1.0));
}