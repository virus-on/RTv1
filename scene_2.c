/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:16:07 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:16:08 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_2.h"
#include <stdlib.h>
#include "mlx.h"
#include "types.h"
#include "sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "plane.h"
#include "tools.h"

t_material	*init_materials_s2(void)
{
	t_material	*materials;

	materials = malloc(sizeof(t_material) * 2);
	materials[0].diffuse = (t_color){0.4, 0.4, 0.4};
	materials[0].reflection = 0.99;
	materials[0].specular = 0.0;
	materials[0].spec_pow = 0;
	materials[1].diffuse.r = 0.6;
	materials[1].diffuse.g = 0.1;
	materials[1].diffuse.b = 0.1;
	materials[1].reflection = 0;
	materials[1].specular = 0.6;
	materials[1].spec_pow = 40;
	return (materials);
}

void		init_objects_s2_2(t_scene **sc, t_material *materials)
{
	t_plane	*planes;

	planes = malloc(sizeof(t_plane) * 3);
	planes[0].n = (t_vector){-1, 0, 0};
	planes[0].q = (t_vector){1500, 0, 0};
	planes[0].material = materials[0];
	planes[1].n = (t_vector){0, 1, 0};
	planes[1].q = (t_vector){0, -1500, 0};
	planes[1].material = materials[0];
	planes[2].n = (t_vector){0, -1, 0};
	planes[2].q = (t_vector){0, 1500, 0};
	planes[2].material = materials[0];
	(*sc)->objects[4] = new_plane(planes[0]);
	(*sc)->objects[5] = new_plane(planes[1]);
	(*sc)->objects[6] = new_plane(planes[2]);
}

void		init_objects_s2(t_scene **sc)
{
	t_sphere	*spheres;
	t_plane		*planes;
	t_material	*materials;

	spheres = malloc(sizeof(t_sphere));
	planes = malloc(sizeof(t_plane) * 3);
	materials = init_materials_s2();
	spheres[0].pos = (t_vector){0, 0, 0};
	spheres[0].radius = 200;
	spheres[0].material = materials[1];
	planes[0].n = (t_vector){0, 0, -1};
	planes[0].q = (t_vector){0, 0, 1500};
	planes[0].material = materials[0];
	planes[1].n = (t_vector){0, 0, 1};
	planes[1].q = (t_vector){0, 0, -1500};
	planes[1].material = materials[0];
	planes[2].n = (t_vector){1, 0, 0};
	planes[2].q = (t_vector){-1500, 0, 0};
	planes[2].material = materials[0];
	(*sc)->objects[0] = new_sphere(spheres[0].pos,
									spheres[0].radius, spheres[0].material);
	(*sc)->objects[1] = new_plane(planes[0]);
	(*sc)->objects[2] = new_plane(planes[1]);
	(*sc)->objects[3] = new_plane(planes[2]);
	init_objects_s2_2(sc, materials);
}

void		init_lights_s2(t_scene **sc)
{
	t_light	*lights;

	lights = malloc(sizeof(t_light) * 6);
	lights[0].pos = (t_vector){0, 0, -750};
	lights[0].intensity = (t_color) {0.5, 0, 0};
	lights[1].pos = (t_vector){0, 0, 750};
	lights[1].intensity = (t_color) {0.5, 0, 0};
	lights[2].pos = (t_vector){0, 750, 0};
	lights[2].intensity = (t_color) {0, 0.5, 0};
	lights[3].pos = (t_vector){0, -750, 0};
	lights[3].intensity = (t_color) {0, 0.5, 0};
	lights[4].pos = (t_vector){-750, 0, 0};
	lights[4].intensity = (t_color) {0, 0, 0.5};
	lights[5].pos = (t_vector){750, 0, 0};
	lights[5].intensity = (t_color) {0, 0, 0.5};
	(*sc)->lights[0] = &lights[0];
	(*sc)->lights[1] = &lights[1];
	(*sc)->lights[2] = &lights[2];
	(*sc)->lights[3] = &lights[3];
	(*sc)->lights[4] = &lights[4];
	(*sc)->lights[5] = &lights[5];
}

void		init_scene_s2(t_scene **sc)
{
	(*sc)->objects = (t_object**)malloc(sizeof(t_object*) * 7);
	(*sc)->obj_count = 7;
	init_objects_s2(sc);
	(*sc)->lights = (t_light**)malloc(sizeof(t_light*) * 6);
	(*sc)->light_count = 6;
	init_lights_s2(sc);
}
