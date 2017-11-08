/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:12:23 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:12:29 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "tools.h"
#include "compute_cone.h"

void	compute_abc(t_ray *r, t_cone *cone, double *out)
{
	double		dot[2];
	t_vector	mult[2];
	t_vector	sub[2];
	t_vector	dp;

	dp = v_sub(&r->start, &cone->pos);
	dot[0] = v_dot(&r->dir, &cone->dir);
	mult[0] = v_scale(dot[0], &cone->dir);
	sub[0] = v_sub(&r->dir, &mult[0]);
	dot[1] = v_dot(&dp, &cone->dir);
	mult[1] = v_scale(dot[1], &cone->dir);
	sub[1] = v_sub(&dp, &mult[1]);
	out[0] = cone->sq_cos * v_dot(&sub[0], &sub[0]);
	out[0] -= cone->sq_sin * dot[0] * dot[0];
	out[1] = 2 * cone->sq_cos * v_dot(&sub[0], &sub[1]);
	out[1] -= 2 * cone->sq_sin * dot[0] * dot[1];
	out[2] = cone->sq_cos * v_dot(&sub[1], &sub[1]);
	out[2] -= cone->sq_sin * dot[1] * dot[1];
}
