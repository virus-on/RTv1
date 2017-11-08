/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:17:58 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:18:00 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "types.h"

t_vector	normalize(t_vector *v)
{
	double		w;
	t_vector	norm;

	norm = *v;
	w = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	norm.x /= w;
	norm.y /= w;
	norm.z /= w;
	return (norm);
}

double		v_cos(t_vector *v1, t_vector *v2)
{
	double	a;
	double	b;
	double	c;
	double	cos;

	a = v_dot(v1, v2);
	b = v_dot(v1, v1);
	c = v_dot(v2, v2);
	cos = a / (b * c);
	return (cos);
}

int			is_inter(t_ray *ray, t_scene *sc, double distance)
{
	int		i;
	double	t;

	i = -1;
	t = 1.79769e+308;
	while (++i < sc->obj_count)
		if (sc->objects[i]->intersect(ray, sc->objects[i]->data, &t))
			if (t < distance)
				return (0);
	return (1);
}

void		x_rotation(t_vector *p, double angle)
{
	register double		y_init;
	register double		z_init;

	y_init = p->y;
	z_init = p->z;
	p->y = (y_init * cos(angle) + z_init * sin(angle));
	p->z = (-y_init) * sin(angle) + z_init * cos(angle);
}

void		y_rotation(t_vector *p, double angle)
{
	register double		x_init;
	register double		z_init;

	x_init = p->x;
	z_init = p->z;
	p->x = x_init * cos(angle) + (z_init) * sin(angle);
	p->z = (-x_init) * sin(angle) + z_init * cos(angle);
}
