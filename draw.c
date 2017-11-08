/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:40:56 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:40:59 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "draw.h"
#include "pthread.h"
#include "types.h"
#include "strings.h"
#include <unistd.h>

void	det_colour(t_scene *sc)
{
	t_ray			light_ray;
	double			t;
	double			k;
	register int	j;
	t_vector		dist;

	C_MAT = *(C_OBJ->get_material(C_OBJ->data));
	j = -1;
	while (++j < sc->light_count)
	{
		dist = v_sub(&sc->lights[j]->pos, &sc->new_start);
		t = sqrt(v_dot(&dist, &dist));
		if (v_dot(&sc->n, &dist) <= 0.0 || t <= 0.0)
			continue;
		light_ray.start = sc->new_start;
		light_ray.dir = v_scale((1 / t), &dist);
		if (is_inter(&light_ray, sc, t))
		{
			compute_colour(&light_ray, sc, &t, &k);
			sc->pixel.r += t * sc->lights[j]->intensity.r * C_MAT.diffuse.r + k;
			sc->pixel.g += t * sc->lights[j]->intensity.g * C_MAT.diffuse.g + k;
			sc->pixel.b += t * sc->lights[j]->intensity.b * C_MAT.diffuse.b + k;
		}
	}
}

int		find_intersection(t_scene *sc)
{
	t_vector		scaled;
	double			t;
	register int	i;

	t = 1.79769e+308;
	C_OBJ = NULL;
	i = -1;
	while (++i < sc->obj_count)
		if (sc->objects[i]->intersect(&sc->ray, sc->objects[i]->data, &t))
			C_OBJ = sc->objects[i];
	if (!C_OBJ)
		return (0);
	scaled = v_scale(t, &RAY_DIR);
	sc->new_start = v_sum(&RAY_START, &scaled);
	C_OBJ->get_normal((void*)sc);
	if (!v_dot(&sc->n, &sc->n))
		return (0);
	det_colour(sc);
	sc->coef *= C_MAT.reflection;
	RAY_START = sc->new_start;
	t = 2.0f * v_dot(&RAY_DIR, &sc->n);
	scaled = v_scale(t, &sc->n);
	RAY_DIR = v_sub(&RAY_DIR, &scaled);
	sc->level++;
	return (1);
}

void	init(t_scene *sc, double x, double y)
{
	double		fov;
	t_vector	view_vector;
	t_vector	temp;

	fov = tan(DEG_TO_RAD(sc->fov) / 2);
	view_vector = (t_vector) {(((x + 0.5f) / WIDTH) * 2.0f - 1.0f) *
		fov * WIDTH / HEIGHT,
		-(((y + 0.5f) / HEIGHT) * 2.0f - 1.0f) * fov, -1.0f};
	sc->pixel = (t_color){0, 0, 0};
	sc->level = 0;
	sc->coef = 1.0;
	RAY_START = sc->cam.pos;
	temp = (t_vector) {X_AXIS.x, Y_AXIS.x, Z_AXIS.x};
	RAY_DIR.x = v_dot(&view_vector, &temp);
	temp = (t_vector) {X_AXIS.y, Y_AXIS.y, Z_AXIS.y};
	RAY_DIR.y = v_dot(&view_vector, &temp);
	temp = (t_vector) {X_AXIS.z, Y_AXIS.z, Z_AXIS.z};
	RAY_DIR.z = v_dot(&view_vector, &temp);
	RAY_DIR = normalize(&RAY_DIR);
}

void	pthread_draw(t_scene *sc)
{
	register int	i;
	t_thread_param	data[THREADS];
	pthread_t		thread[THREADS];

	i = 0;
	while (i < THREADS)
	{
		data[i].sc = *sc;
		data[i].start = HEIGHT / THREADS * i;
		data[i].end = HEIGHT / THREADS * (i + 1);
		pthread_create(&(thread[i]), NULL, draw, &(data[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thread[i++], NULL);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, 0, 0);
}

void	*draw(void *data)
{
	int				x;
	int				y;
	t_thread_param	d;
	t_scene			sc;

	d = *(t_thread_param*)data;
	sc = d.sc;
	x = -1;
	y = d.start - 1;
	count_axis(&sc);
	while (++y != d.end)
	{
		while (++x < WIDTH)
			anti_aliasing(&sc, x, y);
		x = -1;
	}
	pthread_exit(NULL);
}
