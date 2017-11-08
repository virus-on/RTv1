/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:15:23 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:15:24 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "tools.h"

int			intersect_plane(t_ray *r, void *d, double *t)
{
	t_plane		*p;
	t_vector	v_temp;
	double		dist;

	p = (t_plane*)d;
	if (v_dot(&p->n, &r->dir) == 0)
		return (0);
	v_temp = v_sub(&p->q, &r->start);
	dist = v_dot(&p->n, &v_temp) / v_dot(&p->n, &r->dir);
	if (dist > 0.001 && dist < *t)
	{
		*t = dist;
		return (1);
	}
	return (0);
}

t_vector	*get_pos_plane(void *data)
{
	t_plane	*p;

	p = (t_plane*)data;
	return (&(p->q));
}

t_material	*get_material_plane(void *data)
{
	t_plane	*p;

	p = (t_plane*)data;
	return (&(p->material));
}

void		get_normal_plane(void *data)
{
	t_scene	*sc;
	t_plane	*p;
	double	temp;

	sc = (t_scene*)data;
	p = (t_plane*)C_OBJ->data;
	sc->n = p->n;
	temp = v_dot(&sc->n, &sc->n);
	if (temp == 0)
		sc->n = (t_vector){0, 0, 0};
	temp = 1.0 / sqrt(temp);
	sc->n = v_scale(temp, &sc->n);
}

t_object	*new_plane(t_plane obj)
{
	t_object	*out_plane;
	t_plane		*p;

	p = (t_plane*)malloc(sizeof(t_plane));
	*p = obj;
	out_plane = (t_object*)malloc(sizeof(t_object));
	out_plane->data = (void*)p;
	out_plane->intersect = &intersect_plane;
	out_plane->get_pos = &get_pos_plane;
	out_plane->get_material = &get_material_plane;
	out_plane->get_normal = &get_normal_plane;
	return (out_plane);
}
