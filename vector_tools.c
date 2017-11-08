/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:17:47 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:17:48 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_vector	v_sub(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

t_vector	v_sum(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vector	v_scale(double c, t_vector *v1)
{
	t_vector	result;

	result.x = v1->x * c;
	result.y = v1->y * c;
	result.z = v1->z * c;
	return (result);
}

t_vector	cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

double		v_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
