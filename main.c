/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:15:11 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:15:12 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include "types.h"
#include "sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "plane.h"
#include "tools.h"
#include "draw.h"
#include "scene_1.h"
#include "scene_2.h"

int		check_key_state(int keycode, t_scene *sc)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 14)
		sc->fov -= 1;
	if (keycode == 12)
		sc->fov += 1;
	if (keycode == 0)
		sc->cam.pos = rotate_around_y(&sc->cam.pos, &sc->cam.dir, 0.05f);
	if (keycode == 2)
		sc->cam.pos = rotate_around_y(&sc->cam.pos, &sc->cam.dir, -0.05f);
	if (keycode == 13)
		sc->cam.pos = rotate_around_x(&sc->cam.pos, &sc->cam.dir, 0.05f);
	if (keycode == 1)
		sc->cam.pos = rotate_around_x(&sc->cam.pos, &sc->cam.dir, -0.05f);
	if (keycode == 125)
		sc->exposition += 0.1;
	if (keycode == 126)
		sc->exposition -= 0.1;
	pthread_draw(sc);
	return (0);
}

t_scene	scene_params_init(void)
{
	t_scene	sc;
	int		p;

	sc.exposition = -2.0;
	sc.fov = 90;
	sc.n = (t_vector){0, 0, 0};
	sc.cam.dir = (t_vector) {0, 0, 0};
	sc.cam.pos = (t_vector) {0, 0, -1000};
	sc.mlx = mlx_init();
	sc.win = mlx_new_window(sc.mlx, WIDTH, HEIGHT, "RTv1");
	sc.img = mlx_new_image(sc.mlx, WIDTH, HEIGHT);
	sc.canvas = mlx_get_data_addr(sc.img, &p, &p, &p);
	sc.cam.pos = rotate_around_y(&sc.cam.pos, &sc.cam.dir, 0.37);
	return (sc);
}

int		ft_exit(void *gg)
{
	gg = 0;
	exit(0);
}

int		main(int ac, char **av)
{
	t_scene	sc;
	t_scene	*init;

	if (ac == 2 && (av[1][0] == '1' || av[1][0] == '2'))
	{
		sc = scene_params_init();
		init = &sc;
		if (av[1][0] == '1')
			init_scene_s1(&init);
		else
			init_scene_s2(&init);
		pthread_draw(&sc);
		mlx_hook(sc.win, 17, 1L << 17, ft_exit, NULL);
		mlx_hook(sc.win, 2, 3, check_key_state, &sc);
		mlx_loop(sc.mlx);
	}
	write(1, "To launch this great rt please, use {1|2} as a param\n", 53);
	return (0);
}
