/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:39:29 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/20 15:07:12 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_plane(t_plane *plane)
{
	t_plane *tmp;

	while (plane)
	{
		tmp = plane->next;
		free(plane);
		plane = tmp;
	}
}

void	free_cam(t_cam *cam)
{
	t_cam *tmp;
	t_cam *head;

	head = cam;
	while (cam)
	{
		tmp = cam->next;
		free(cam);
		if (tmp == head)
			break ;
		cam = tmp;
	}
}

void	return_free(t_scene *scene, int *arr)
{
	free(scene->resol);
	if (scene->ambient)
		free(scene->ambient);
	free_cam(scene->cam);
	if (scene->light)
		free_light(scene->light);
	if (scene->obj.trian)
		free_trian(scene->obj.trian);
	if (scene->obj.sphere)
		free_sphere(scene->obj.sphere);
	if (scene->obj.square)
		free_square(scene->obj.square);
	if (scene->obj.clndr)
		free_clndr(scene->obj.clndr);
	if (scene->obj.plane)
		free_plane(scene->obj.plane);
	free(scene);
	free(arr);
}
