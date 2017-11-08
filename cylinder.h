/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:14:08 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:14:10 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "types.h"

int			intersect_cylinder(t_ray *r, void *d, double *t);

t_vector	get_pos_cylinder(void *data);

t_material	get_material_cylinder(void *data);

t_object	*new_cylinder(t_cylinder obj);

#endif
