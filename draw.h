/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:14:34 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:14:36 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdlib.h>
# include <math.h>
# include "types.h"
# include "tools.h"
# include "sphere.h"

void	det_colour(t_scene *sc);
int		find_intersection(t_scene *sc);
void	init(t_scene *sc, double x, double y);
void	pthread_draw(t_scene *sc);
void	*draw(void *data);
void	anti_aliasing(t_scene *sc, int x, int y);

#endif
