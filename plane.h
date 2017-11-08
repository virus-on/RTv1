/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:15:32 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:15:33 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "types.h"

int			intersect_plane(t_ray *r, void *d, float *t);
t_vector	get_pos_plane(void *data);
t_material	get_material_plane(void *data);
t_object	*new_plane(t_plane obj);

#endif
