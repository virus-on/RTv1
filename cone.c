/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:13:19 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:13:22 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "tools.h"
#include "compute_cone.h"
#include <unistd.h>

int			intersect_cone(t_ray *r, void *d, double *t)
{
	double	ops[4];
	double	dist;

	compute_abc(r, d, (double*)ops);
	TMP = B * B - 4 * A * C;
	if (TMP < 0)
		return (0);
	else
	{
		TMP = sqrt(TMP);
		dist = MAX((-B + TMP) / (2 * A), 0);
		B = MAX((-B - TMP) / (2 * A), 0);
		A = MIN(B, dist) > 0 ? MIN(B, dist) : MAX(B, dist);
		if ((A > 0.00001) && (A < *t))
			*t = A;
		else
			return (0);
	}
	return (1);
}

t_vector	*get_pos_cone(void *data)
{
	t_cone *c;

	c = (t_cone*)data;
	return (&(c->pos));
}

t_material	*get_material_cone(void *data)
{
	t_cone *c;

	c = (t_cone*)data;
	return (&(c->material));
}

void		get_normal_cone(void *data)
{
	t_vector	b;
	t_scene		*sc;
	t_cone		*c;
	double		temp;

	sc = (t_scene*)data;
	c = (t_cone*)C_OBJ->data;
	b = v_sub(&sc->new_start, &c->pos);
	sc->n = v_scale(v_cos(&b, &c->dir), &c->dir);
	sc->n = v_sub(&b, &sc->n);
	sc->n = cross_product(&b, &sc->n);
	sc->n = cross_product(&sc->n, &b);
	temp = v_dot(&sc->n, &sc->n);
	if (temp == 0)
		sc->n = (t_vector){0, 0, 0};
	temp = 1.0f / sqrt(temp);
	sc->n = v_scale(temp, &sc->n);
}

t_object	*new_cone(t_cone obj)
{
	t_object	*out_cone;
	t_cone		*c;

	c = (t_cone*)malloc(sizeof(t_cone));
	*c = obj;
	out_cone = (t_object*)malloc(sizeof(t_object));
	c->sq_cos = SQUARE(cos(c->angel));
	c->sq_sin = SQUARE(sin(c->angel));
	out_cone->data = (void*)c;
	out_cone->intersect = &intersect_cone;
	out_cone->get_pos = &get_pos_cone;
	out_cone->get_normal = &get_normal_cone;
	out_cone->get_material = &get_material_cone;
	return (out_cone);
}
