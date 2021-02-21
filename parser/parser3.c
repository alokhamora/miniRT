/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:42:12 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/16 19:03:43 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			add_to_cycle(t_cam **c, t_cam cam)
{
	t_cam	*prev;
	t_cam	*next;
	t_cam	*temp;

	temp = malloc(sizeof(t_cam));
	if (temp == NULL)
		return (-1);
	ft_memcpy(temp, &cam, sizeof(t_cam));
	if (*c == NULL)
	{
		temp->next = temp;
		*c = temp;
	}
	else
	{
		prev = *c;
		next = prev->next;
		prev->next = temp;
		temp->next = next;
	}
	return (1);
}

t_vector	get_normal(char **line)
{
	t_vector	ret;

	ret = get_vector(line);
	if (vect_len(ret) == 0)
		exit_pars();
	ret = normalize(ret);
	return (ret);
}

int			pars_a(char **line, t_scene *scene)
{
	if (scene->ambient != NULL)
		exit_pars();
	(*line)++;
	scene->ambient = ft_calloc(sizeof(t_color), 1);
	if (!scene->ambient)
		err_exit("Memory allocation error");
	*scene->ambient = pcolr_mult(get_double(line, 0), get_color(line));
	return (1);
}

int			pars_ra(char **line, t_scene *scene)
{
	if (**line == 'R')
	{
		if (scene->resol != NULL)
			exit_pars();
		(*line)++;
		scene->resol = ft_calloc(1, sizeof(t_resol));
		if (!scene->resol)
			err_exit("Memory allocation error");
		scene->resol->width = get_int(line, 0);
		scene->resol->height = get_int(line, 0);
		if (scene->resol->width >= 2560)
			scene->resol->width = 2560;
		if (scene->resol->height >= 1440)
			scene->resol->height = 1440;
		if (scene->resol->width <= 0 || scene->resol->height <= 0)
			exit_pars();
	}
	if (**line == 'A')
		pars_a(line, scene);
	return (1);
}

int			pars_cam(char **line, t_scene *scene)
{
	t_cam	temp;

	temp.view_p = get_vector(line);
	temp.normal_v = get_normal(line);
	temp.fov = get_int(line, 0);
	if (add_to_cycle(&(scene->cam), temp) < 0)
		err_exit("Memory allocation fail");
	return (1);
}
