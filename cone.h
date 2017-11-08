/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:13:31 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:13:33 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "types.h"
# include "compute_cone.h"

int			intersect_cone(t_ray *r, void *d, double *t);
t_vector	get_pos_cone(void *data);
t_material	get_material_cone(void *data);
t_object	*new_cone(t_cone obj);

#endif
