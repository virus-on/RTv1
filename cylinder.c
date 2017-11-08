/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:13:51 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:13:53 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "tools.h"
#include "compute_cylinder.h"

int			intersect_cylinder(t_ray *r, void *d, double *t)
{
	double	ops[4];
	double	dist;

	compute_cylinder(r, d, ops);
	TMP = B * B - 4 * A * C;
	if (TMP < 0)
		return (0);
	else
	{
		TMP = sqrt(TMP);
		dist = MAX((-B + TMP) / (2 * A), 0);
		B = MAX((-B - TMP) / (2 * A), 0);
		A = MIN(B, dist) > 0 ? MIN(B, dist) : MAX(B, dist);
		if ((A > 0.001) && (A < *t))
			*t = A;
		else
			return (0);
	}
	return (1);
}

t_vector	*get_pos_cylinder(void *data)
{
	t_cylinder	*c;

	c = (t_cylinder*)data;
	return (&(c->pos));
}

t_material	*get_material_cylinder(void *data)
{
	t_cylinder	*c;

	c = (t_cylinder*)data;
	return (&(c->material));
}

void		get_normal_cylinder(void *data)
{
	t_vector	b;
	t_scene		*sc;
	t_cylinder	*c;
	double		temp;

	sc = (t_scene*)data;
	c = (t_cylinder*)C_OBJ->data;
	b = v_sub(&sc->new_start, &c->pos);
	sc->n = v_scale(v_dot(&b, &c->n), &c->n);
	sc->n = v_sub(&b, &sc->n);
	temp = v_dot(&sc->n, &sc->n);
	if (temp == 0)
		sc->n = (t_vector){0, 0, 0};
	temp = 1.0f / sqrt(temp);
	sc->n = v_scale(temp, &sc->n);
}

t_object	*new_cylinder(t_cylinder obj)
{
	t_object	*out_cylinder;
	t_cylinder	*c;

	c = (t_cylinder*)malloc(sizeof(t_cylinder));
	*c = obj;
	out_cylinder = (t_object*)malloc(sizeof(t_object));
	out_cylinder->data = (void*)c;
	out_cylinder->intersect = &intersect_cylinder;
	out_cylinder->get_pos = &get_pos_cylinder;
	out_cylinder->get_material = &get_material_cylinder;
	out_cylinder->get_normal = &get_normal_cylinder;
	return (out_cylinder);
}
