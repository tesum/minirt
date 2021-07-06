/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:56:11 by demilan           #+#    #+#             */
/*   Updated: 2021/07/06 20:07:15 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define MAX_OBJ				100
# define ERR_MAP				250
# define ERR_MALLOC				34
# define ERR_CREATE_ALIGHT		255
# define ERR_CREATE_CAM			256
# define ERR_CREATE_LIGHT		257
# define ERR_CREATE_SPHERE		258
# define ERR_CREATE_PLANE		259
# define ERR_CREATE_CYLINDER	260
# define ERR_REQ_OBJECT			261
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_vec2
{
	double	x;
	double	y;	
}				t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec4;

typedef struct s_mlx
{
	void	*mlx_p;
	void	*win_p;
	
	int		mlx_x;
	int		mlx_y;
	t_vec3	rgb;
	int		color;
}				t_mlx;

typedef struct s_camera
{
	t_vec3		origin;
	t_vec3		direction;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		l_left_corner;
	int			FOV;
}				t_camera;

typedef struct s_sphere
{
	t_vec3		center;
	double		r;
	t_vec3		color_light;
}				t_sphere;

typedef struct s_light
{
	t_vec3	origin;
	double	aspect;
	t_vec3	color;
}				t_light;

typedef struct s_alight
{
	double	aspect;
	t_vec3	color;
}				t_alight;

typedef struct s_plane
{
	t_vec3		origin;
	t_vec3		normalize_vector;
	t_vec3		color;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3		origin;
	t_vec3		normalize_vector;
	double		diameter;
	double		height;
	t_vec3		color;
}				t_cylinder;

typedef struct s_scene
{
	int				width;
	int				hight;
	int				req_count_obj;
	int				c_sp;
	int				c_pl;
	int				c_cy;
	t_alight		alight;
	t_camera		cams;
	t_light			lights;
	t_sphere		sphers[MAX_OBJ];
	t_plane			plane[MAX_OBJ];
	t_cylinder		cylinder[MAX_OBJ];
	
}				t_scene;

t_scene		g_scene;
int			isElem(char *s);

t_vec3		new_vec3(double x, double y, double z);
t_vec2		new_vec2(double x, double y);

// parser
void		parce(char *map);
void		parse_alight(char *str);
void		parse_cam(char *str);
void		parse_light(char *str);
void		parse_sphere(char *str);
void		parse_plane(char *str);
void		parse_cylinder(char *str);
t_vec3		parse_vec3(char **str);

// sphere

double		sphSoftShadow(t_vec3 *ro, t_vec3 *rd, t_vec3 *ce, double ra);

//	My math

double		ft_atof(char **str);
double		f_max(double one, double two);
double		f_min(double one, double two);
double		smoothstep(double min, double max, double value);

// UTILS

char		**ft_split_rt(char const *s, char *c);
void		free_split(char **str);

void		color_pixel(t_mlx *mlx_s, t_vec3 color);
t_vec3		new_rgb(int r, int g, int b);
int			create_rgb(t_vec3 *rgb);
t_vec3		normalize(t_vec3 p);
double		scalar_product(t_vec3 vec1, t_vec3 vec2);
t_vec3		mul_vec(t_vec3 vec, double k);
t_vec3		vec_m_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_p_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_mul_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_div(t_vec3 vec, double k);
double		len_squared(t_vec3 vec3);
t_vec2		get_pixel(t_vec2 resolution, int mlx_x, int mlx_y);

t_vec3		get_ray(double w, double h);

t_scene		*new_scene(t_camera *cam, t_sphere *sphere);
void		new_camera(void);

void		ray_tracing(void *mlx, void *win, t_scene *scene);
// t_vplane	*get_view_plane(double width, double hight, double FOV);
int			sphere_intersect(t_camera *cam, t_vec3 *ray, t_sphere *sphere);

t_light		new_light(t_vec3 origin, double aspect, t_vec3 color);
t_sphere	new_sphere(t_vec3 center, double r, t_vec3 color);

// check
t_vec2		sphIntersect(t_vec3 ro, t_vec3 rd, t_vec3 ce, double ra);
t_vec3		castRay(t_vec3 ro, t_vec3 rd);

void		er_exit(int errno);
void		exit_error(char *error, int code);
#endif