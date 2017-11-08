/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:15:48 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/09/13 15:15:50 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_1.h"
#include "stdio.h"
#include <unistd.h>

t_material	*init_materials_s1(void)
{
	t_material	*materials;

	materials = malloc(sizeof(t_material) * 4);
	materials[0].diffuse = (t_color){1, 0, 0};
	materials[0].reflection = 0.2;
	materials[0].specular = 0.6;
	materials[0].spec_pow = 20;
	materials[1].diffuse = (t_color){0, 1, 0};
	materials[1].reflection = 0;
	materials[1].specular = 0.2;
	materials[1].spec_pow = 20;
	materials[2].diffuse = (t_color){0, 0, 1};
	materials[2].reflection = 0.05;
	materials[2].specular = 0;
	materials[2].spec_pow = 8;
	materials[3].diffuse = (t_color){0.5, 0.5, 0.5};
	materials[3].reflection = 0.99;
	materials[3].specular = 0;
	materials[3].spec_pow = 50;
	return (materials);
}

void		init_objects_s1_2(t_scene **sc, t_material *materials)
{
	t_plane	*planes;
	t_cone	*cones;

	planes = malloc(sizeof(t_plane) * 2);
	cones = malloc(sizeof(t_cone));
	planes[0].n = (t_vector){0, 0, -1};
	planes[0].q = (t_vector){0, 0, 1000};
	planes[0].material = materials[3];
	planes[1].n = (t_vector){0, 1, 0};
	planes[1].q = (t_vector){-300, -300, 1000};
	planes[1].material = materials[3];
	cones->dir = (t_vector){0, 0, 1};
	cones->pos = (t_vector){600, 600, 200};
	cones->angel = DEG_TO_RAD(10);
	cones->material = materials[2];
	(*sc)->objects[4] = new_plane(planes[0]);
	(*sc)->objects[5] = new_plane(planes[1]);
	(*sc)->objects[2] = new_cone(*cones);
}

void		init_objects_s1(t_scene **sc)
{
	t_sphere	*spheres;
	t_cylinder	*cylinders;
	t_material	*materials;

	cylinders = malloc(sizeof(t_cylinder));
	spheres = malloc(sizeof(t_sphere) * 2);
	materials = init_materials_s1();
	spheres[0].pos = (t_vector){200, 300, 0};
	spheres[0].radius = 100;
	spheres[0].material = materials[0];
	spheres[1].pos = (t_vector){400, 400, 0};
	spheres[1].radius = 100;
	spheres[1].material = materials[1];
	cylinders->n = (t_vector){0, 1, 0};
	cylinders->pos = (t_vector){1200, 1600, 500};
	cylinders->radius = 100;
	cylinders->material = materials[0];
	(*sc)->objects[0] = new_sphere(spheres[0].pos,
									spheres[0].radius, spheres[0].material);
	(*sc)->objects[1] = new_sphere(spheres[1].pos,
									spheres[1].radius, spheres[1].material);
	(*sc)->objects[3] = new_cylinder(*cylinders);
	init_objects_s1_2(sc, materials);
}

void		init_lights_s1(t_scene **sc)
{
	t_light	*lights;

	lights = malloc(sizeof(t_light));
	lights[0].pos = (t_vector){0, 2409, -100};
	lights[0].intensity = (t_color){1, 1, 1};
	(*sc)->lights[0] = &lights[0];
}

void		init_scene_s1(t_scene **sc)
{
	(*sc)->objects = (t_object**)malloc(sizeof(t_object*) * 6);
	(*sc)->obj_count = 6;
	init_objects_s1(sc);
	(*sc)->lights = (t_light**)malloc(sizeof(t_light*) * 1);
	(*sc)->light_count = 1;
	init_lights_s1(sc);
}
