/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:17:22 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:17:23 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_material
{
	t_color		diffuse;
	double		reflection;
	double		specular;
	double		spec_pow;
}				t_material;

typedef struct	s_light
{
	t_vector	pos;
	t_color		intensity;
}				t_light;

typedef struct	s_sphere
{
	t_vector	pos;
	double		radius;
	t_material	material;
}				t_sphere;

typedef struct	s_cone
{
	t_vector	pos;
	double		angel;
	double		sq_cos;
	double		sq_sin;
	t_vector	dir;
	t_material	material;
}				t_cone;

typedef struct	s_plane
{
	t_vector	n;
	t_vector	q;
	t_material	material;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	n;
	double		radius;
	t_material	material;
}				t_cylinder;

typedef struct	s_object
{
	void		*data;
	int			(*intersect)(t_ray *r, void *d, double *t);
	t_vector	*(*get_pos)(void *d);
	t_material	*(*get_material)(void *d);
	void		(*get_normal)(void *d);
}				t_object;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	dir;
	t_vector	x_axis;
	t_vector	y_axis;
	t_vector	z_axis;
}				t_camera;

typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*canvas;
	t_object	**objects;
	int			obj_count;
	t_light		**lights;
	int			light_count;
	t_ray		ray;
	t_camera	cam;
	double		coef;
	t_object	*current_obj;
	t_light		*current_light;
	t_material	current_mat;
	t_vector	new_start;
	int			level;
	t_color		pixel;
	t_vector	n;
	double		exposition;
	int			fov;
}				t_scene;

typedef struct	s_thread_param
{
	t_scene		sc;
	int			start;
	int			end;
}				t_thread_param;
#endif
