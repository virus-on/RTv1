/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:15:55 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:15:56 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_1_H
# define SCENE_1_H

# include <stdlib.h>
# include "mlx.h"
# include "types.h"
# include "sphere.h"
# include "cone.h"
# include "cylinder.h"
# include "plane.h"
# include "tools.h"
# include "draw.h"
# include <stdio.h>

void		init_scene_s1(t_scene **sc);

void		init_lights_s1(t_scene **sc);

void		init_objects_s1(t_scene **sc);

t_material	*init_materials_s1();

#endif
