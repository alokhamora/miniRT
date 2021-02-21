/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:12:51 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/20 13:38:28 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		pars_plane(char **line, t_scene *scene)
{
	t_plane *tmp;
	t_plane *ext;

	(*line)++;
	scene->obj.pl = 1;
	tmp = ft_calloc(1, sizeof(t_plane));
	if (tmp == NULL)
		err_exit("Memory allocation error");
	tmp->coord = get_vector(line);
	tmp->normal_v = get_normal(line);
	tmp->color = get_color(line);
	ext = scene->obj.plane;
	if (ext == NULL)
	{
		scene->obj.plane = tmp;
		return (1);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = tmp;
	return (1);
}

int		pars_sqr(char **line, t_scene *scene)
{
	t_square *tmp;
	t_square *ext;

	(*line)++;
	scene->obj.sqr = 1;
	tmp = ft_calloc(1, sizeof(t_square));
	if (tmp == NULL)
		err_exit("Memory allocation error");
	tmp->center = get_vector(line);
	tmp->normal_v = get_normal(line);
	tmp->size = get_double(line, 0);
	tmp->color = get_color(line);
	ext = scene->obj.square;
	if (ext == NULL)
	{
		scene->obj.square = tmp;
		return (1);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = tmp;
	return (1);
}

int		pars_sph(char **line, t_scene *scene)
{
	t_sphere *tmp;
	t_sphere *ext;

	(*line)++;
	scene->obj.sph = 1;
	tmp = ft_calloc(1, sizeof(t_sphere));
	if (tmp == NULL)
		err_exit("Memory allocation error");
	tmp->center = get_vector(line);
	tmp->diamtr = get_double(line, 0);
	tmp->color = get_color(line);
	ext = scene->obj.sphere;
	if (ext == NULL)
	{
		scene->obj.sphere = tmp;
		return (0);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = tmp;
	return (1);
}

int		pars_cyl(char **line, t_scene *scene)
{
	t_clndr *temp;
	t_clndr *ext;

	(*line)++;
	scene->obj.cyl = 1;
	temp = ft_calloc(1, sizeof(t_clndr));
	if (temp == NULL)
		err_exit("Memory allocation error");
	temp->coord = get_vector(line);
	temp->normal_v = get_normal(line);
	temp->diamtr = get_double(line, 0);
	temp->height = get_double(line, 0);
	temp->color = get_color(line);
	ext = scene->obj.clndr;
	if (ext == NULL)
	{
		scene->obj.clndr = temp;
		return (1);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = temp;
	return (1);
}

int		pars_light(char **line, t_scene *scene)
{
	t_light	*temp;
	t_light	*ext;
	double	k;

	(*line)++;
	if (!(temp = ft_calloc(1, sizeof(t_light))))
		err_exit("Memory allocation error");
	temp->coord = get_vector(line);
	k = get_double(line, 0);
	temp->color = pcolr_mult(k, get_color(line));
	ext = scene->light;
	if (ext == NULL)
	{
		scene->light = temp;
		return (1);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = temp;
	return (1);
}
