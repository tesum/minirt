/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:56:11 by demilan           #+#    #+#             */
/*   Updated: 2021/08/17 18:27:29 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define MAX_OBJ				100
# define ERR_MAP				250
# define ERR_SCENE_OBJ			251
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
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf.h"

typedef struct s_inter_t
{
	double	x;
	double	y;	
}				t_inter_t;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_ray
{
	t_vec3	ro;
	t_vec3	rd;
}				t_ray;

typedef struct s_mlx
{
	void	*mlx_p;
	void	*win_p;
	int		color;
	t_vec3	rgb;
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
	t_vec3		color_light;
	t_vec3		pos;
	t_vec3		nor;
	double		t;
	double		r;
}				t_sphere;

typedef struct s_light
{
	t_vec3	origin;
	t_vec3	color;
	double	aspect;
}				t_light;

typedef struct s_alight
{
	t_vec3	color;
	double	aspect;
}				t_alight;

typedef struct s_plane
{
	t_vec3		origin;
	t_vec3		normalize_vector;
	t_vec3		color;
	t_vec3		pos;
	double		t;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3		origin;
	t_vec3		n_vector;
	t_vec3		normal;
	t_vec3		color;
	t_vec3		pos;
	double		diameter;
	double		h;
	double		t;
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
	t_mlx			mlx;
	double			itmin;
}				t_scene;

t_scene		g_scene;

// new
t_vec3		new_vec3(double x, double y, double z);
t_inter_t	new_intert(double x, double y);
t_ray		new_ray(t_vec3 ro, t_vec3 rd);
void		new_camera(void);

// parser
void		parce(char *map);
void		parse_alight(char *str);
void		parse_cam(char *str);
void		parse_light(char *str);
void		parse_sphere(char *str);
void		parse_plane(char *str);
void		parse_cylinder(char *str);
t_vec3		parse_vec3(char **str);

// intersects
t_vec3		castRay(t_ray ray);
double		sph_intersect(t_vec3 ro, t_vec3 rd, t_sphere *sphere);
double		pl_intersect(t_vec3 ro, t_vec3 rd, t_plane *plane);
double		cy_inter(t_vec3 ro, t_vec3 rd, t_cylinder *cylinder);
double		limit(t_inter_t t, t_cylinder *cy, t_ray ray);

//	My math
double		ft_atof(char **str);
double		f_max(double one, double two);
double		f_min(double one, double two);
double		smoothstep(double min, double max, double value);

// UTILS
void		free_split(char **str);
void		color_pixel(t_mlx *mlx, t_vec3 color);
void		exit_error(char *error, int code);
char		**ft_split_rt(char const *s, char *c);
double		diffuse(t_vec3 pos, t_vec3 normal, t_vec3 rd);
double		len_squared(t_vec3 vec3);
double		scalar_product(t_vec3 vec1, t_vec3 vec2);
t_vec3		normalize(t_vec3 p);
t_vec3		mul_vec(t_vec3 vec, double k);
t_vec3		vec_m_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_p_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_mul_vec(t_vec3 vec1, t_vec3 vec2);
t_vec3		cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_div(t_vec3 vec, double k);
t_vec3		get_ray(double w, double h, t_camera cam);

// hooks
int			close_esc(int keycode, t_mlx *img);
int			destroy(void);
#endif