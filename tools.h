/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:17:00 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:17:02 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "types.h"
# include "math.h"

# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define SQUARE(x) ((x) * (x))
# define ABS(X) ((X) < 0 ? -(X) : (X))
# define DEG_TO_RAD(X) ((X) * PI / 180)
# define WIDTH  1280
# define HEIGHT 720
# define THREADS 4
# define SAMPLES 1
# define MAX_LVL 10
# define PI (3.14159265)
# define X_AXIS (sc->cam.x_axis)
# define Y_AXIS (sc->cam.y_axis)
# define Z_AXIS (sc->cam.z_axis)
# define C_MAT (sc->current_mat)
# define C_OBJ (sc->current_obj)
# define RAY_DIR (sc->ray.dir)
# define RAY_START (sc->ray.start)
# define A (ops[0])
# define B (ops[1])
# define C (ops[2])
# define TMP (ops[3])

double			v_dot(t_vector *v1, t_vector *v2);
t_vector		v_scale(double c, t_vector *v1);
t_vector		v_sum(t_vector *v1, t_vector *v2);
t_vector		v_sub(t_vector *v1, t_vector *v2);
double			deg_to_rad(int deg);
t_vector		cross_product(t_vector *v1, t_vector *v2);
t_vector		normalize(t_vector *v);
void			move(double speed, t_vector *point, t_vector direction);
void			x_rotation(t_vector *p, double angle);
void			y_rotation(t_vector *p, double angle);
void			z_rotation(t_vector *p, double angle);
t_vector		rotate_around_x(t_vector *rot, t_vector *around, double angel);
t_vector		rotate_around_y(t_vector *rot, t_vector *around, double angel);
t_vector		rotate_around_z(t_vector *rot, t_vector *around, double angel);
void			count_axis(t_scene *sc);
void			compute_colour(t_ray *t_light_ray, t_scene *sc,
								double *t, double *k);
int				is_inter(t_ray *ray, t_scene *sc, double distance);
void			exposition(t_color *c, t_scene *sc);
double			vector_mag(t_vector *v);
double			v_cos(t_vector *v1, t_vector *v2);
double			vector_sin(t_vector *v1, t_vector *v2);

#endif
