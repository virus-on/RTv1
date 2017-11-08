/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:16:31 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:16:32 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "tools.h"

int			intersect_sphere(t_ray *r, void *d, double *t)
{
	double		ops[4];
	t_sphere	*s;
	t_vector	dist;

	s = d;
	A = v_dot(&r->dir, &r->dir);
	dist = v_sub(&r->start, &s->pos);
	B = 2 * v_dot(&r->dir, &dist);
	C = v_dot(&dist, &dist) - (s->radius * s->radius);
	TMP = B * B - 4 * A * C;
	if (TMP < 0)
		return (0);
	else
	{
		TMP = sqrt(TMP);
		dist.x = MAX((-B + TMP) / (2 * A), 0);
		B = MAX((-B - TMP) / (2 * A), 0);
		A = MIN(B, dist.x) > 0 ? MIN(B, dist.x) : MAX(B, dist.x);
		if ((A > 0.001) && (A < *t))
			*t = A;
		else
			return (0);
	}
	return (1);
}

t_vector	*get_pos_sphere(void *data)
{
	t_sphere	*sp;

	sp = (t_sphere*)data;
	return (&(sp->pos));
}

void		get_normal_sphere(void *data)
{
	t_scene	*sc;
	double	temp;

	sc = (t_scene*)data;
	sc->n = v_sub(&sc->new_start, C_OBJ->get_pos(C_OBJ->data));
	temp = v_dot(&sc->n, &sc->n);
	if (temp == 0)
		sc->n = (t_vector){0, 0, 0};
	temp = 1.0 / sqrt(temp);
	sc->n = v_scale(temp, &sc->n);
}

t_material	*get_material_sphere(void *data)
{
	t_sphere	*sp;

	sp = (t_sphere*)data;
	return (&(sp->material));
}

t_object	*new_sphere(t_vector pos, double radius, t_material mat)
{
	t_object	*out_sphere;
	t_sphere	*sp;

	sp = (t_sphere*)malloc(sizeof(t_sphere));
	sp->pos = pos;
	sp->radius = radius;
	sp->material = mat;
	out_sphere = (t_object*)malloc(sizeof(t_object));
	out_sphere->data = (void*)sp;
	out_sphere->intersect = &intersect_sphere;
	out_sphere->get_normal = &get_normal_sphere;
	out_sphere->get_pos = &get_pos_sphere;
	out_sphere->get_material = &get_material_sphere;
	return (out_sphere);
}
