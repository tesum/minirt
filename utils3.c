#include "miniRT.h"

t_vec3	cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	new.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	new.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (new);
}

double	len_squared(t_vec3 vec3)
{
	return (vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
}

t_vec3	vec_mul_vec(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x * vec2.x;
	vec.y = vec1.y * vec2.y;
	vec.z = vec1.z * vec2.z;
	return (vec);
}

t_vec3	get_ray(double w, double h)
{
	t_camera	cam;
	t_vec3		ray;

	cam = g_scene.cams;
	// printf("========= %f\n", cam.vertical.x);
	// printf("========= %f\n", cam.vertical.y);
	// printf("========= %f\n", cam.vertical.z);
	// ray = vec_m_vec(vec_p_vec(vec_p_vec(cam.l_left_corner, mul_vec(cam.horizontal, w)), mul_vec(cam.vertical, h)), cam.origin);
	ray = vec_p_vec(cam.l_left_corner,
		vec_p_vec(mul_vec(cam.horizontal, w),
			vec_m_vec(mul_vec(cam.vertical, h), cam.origin)));
	return (normalize(ray));
}