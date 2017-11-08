/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:11:58 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:12:12 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "draw.h"
#include "pthread.h"
#include "types.h"
#include "unistd.h"

void	write_to_canvas(t_color *out, t_scene *sc, int x, int y)
{
	exposition(out, sc);
	sc->canvas[(x + y * WIDTH) * 4 + 2] =
	(unsigned char)MIN(out->r * 255.0f, 255.0f);
	sc->canvas[(x + y * WIDTH) * 4 + 1] =
	(unsigned char)MIN(out->g * 255.0f, 255.0f);
	sc->canvas[(x + y * WIDTH) * 4 + 0] =
	(unsigned char)MIN(out->b * 255.0f, 255.0f);
}

void	anti_aliasing(t_scene *sc, int x, int y)
{
	double	step;
	double	sx;
	double	sy;
	t_color	out;

	step = 1.0 / SAMPLES;
	sy = -0.5 + step / 2;
	out = (t_color){0, 0, 0};
	while (sy < 0.49)
	{
		sx = -0.5 + step / 2;
		while (sx < 0.49)
		{
			init(sc, x + sx, y + sy);
			sc->coef = sc->coef / (SQUARE(SAMPLES));
			while ((sc->coef > 0.0f) && (sc->level < MAX_LVL))
				if (!find_intersection(sc))
					break ;
			out = (t_color){out.r + sc->pixel.r, out.g + sc->pixel.g,
				out.b + sc->pixel.b};
			sx += step;
		}
		sy += step;
	}
	write_to_canvas(&out, sc, x, y);
}
