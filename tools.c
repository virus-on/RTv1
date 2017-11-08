/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:16:50 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:16:51 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "types.h"
#include "math.h"

void		count_axis(t_scene *sc)
{
	t_vector	temp;
	t_vector	up;

	up = (t_vector){0, 1, 0};
	temp = v_sub(&sc->cam.pos, &sc->cam.dir);
	Z_AXIS = normalize(&temp);
	temp = cross_product(&up, &Z_AXIS);
	X_AXIS = normalize(&temp);
	Y_AXIS = cross_product(&Z_AXIS, &X_AXIS);
}

void		compute_colour(t_ray *light_ray, t_scene *sc, double *t, double *k)
{
	t_vector	spec;

	spec = v_scale(2.0 * v_dot(&light_ray->dir, &sc->n), &sc->n);
	spec = v_sub(&light_ray->dir, &spec);
	*k = v_dot(&sc->ray.dir, &spec);
	*k = *k > 0 ? pow(*k, C_MAT.spec_pow) * C_MAT.specular * sc->coef : 0.0;
	*t = v_dot(&light_ray->dir, &sc->n) * sc->coef;
}

void		exposition(t_color *c, t_scene *sc)
{
	c->r = 1.0 - exp(c->r * sc->exposition);
	c->g = 1.0 - exp(c->g * sc->exposition);
	c->b = 1.0 - exp(c->b * sc->exposition);
}

t_vector	rotate_around_x(t_vector *rot, t_vector *around, double angel)
{
	t_vector	v;

	v = v_sub(rot, around);
	x_rotation(&v, angel);
	v = v_sum(&v, around);
	return (v);
}

t_vector	rotate_around_y(t_vector *rot, t_vector *around, double angel)
{
	t_vector	v;

	v = v_sub(rot, around);
	y_rotation(&v, angel);
	v = v_sum(&v, around);
	return (v);
}
