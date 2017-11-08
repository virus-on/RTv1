/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:26:57 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:27:01 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute_cylinder.h"
#include "types.h"
#include "tools.h"

void	compute_cylinder(t_ray *r, void *d, double ops[4])
{
	t_cylinder	*c;
	t_vector	v_temp[3];

	c = (t_cylinder*)d;
	TMP = v_dot(&r->dir, &c->n);
	v_temp[0] = v_scale(TMP, &c->n);
	v_temp[0] = v_sub(&r->dir, v_temp);
	A = v_dot(v_temp, v_temp);
	v_temp[2] = v_sub(&r->start, &c->pos);
	TMP = v_dot(&(v_temp[2]), &c->n);
	v_temp[1] = v_scale(TMP, &c->n);
	v_temp[1] = v_sub(&(v_temp[2]), &(v_temp[1]));
	B = 2 * v_dot(&(v_temp[0]), &(v_temp[1]));
	C = v_dot(&(v_temp[1]), &v_temp[1]) - c->radius * c->radius;
}
