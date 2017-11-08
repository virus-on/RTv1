/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:16:39 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:16:40 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "types.h"

int			intersect_sphere(t_ray *r, void *d, double *t);
t_vector	get_pos_sphere(void *data);
t_material	get_material_sphere(void *data);
t_object	*new_sphere(t_vector pos, double radius, t_material mat);

#endif
