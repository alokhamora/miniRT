/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:40:07 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 14:26:45 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	correct(t_scene *scene)
{
	t_light *tmp;

	if (!scene->cam)
		exit_pars();
	if (!scene->resol)
		exit_pars();
	if (scene->ambient)
	{
		if (!scene->light)
		{
			tmp = ft_calloc(sizeof(t_light), 1);
			scene->light = tmp;
		}
		tmp = scene->light;
		while (tmp)
		{
			tmp->ambient = *scene->ambient;
			tmp = tmp->next;
		}
	}
}

void	parser1(t_scene *scene, char **line)
{
	if (**line == 'c')
	{
		(*line)++;
		if (**line == 'y')
			pars_cyl(line, scene);
		else if (!ft_isalnum(**line))
			pars_cam(line, scene);
		else
			exit_pars();
	}
	if (**line == 'l')
		pars_light(line, scene);
	if (**line == 's')
	{
		(*line)++;
		if (**line == 'p')
			pars_sph(line, scene);
		else if (**line == 'q')
			pars_sqr(line, scene);
		else
			exit_pars();
	}
}

void	parser2(t_scene *scene, char **line)
{
	if (**line == 'p')
	{
		(*line)++;
		if (**line != 'l')
			exit_pars();
		pars_plane(line, scene);
	}
	if (**line == 't')
	{
		(*line)++;
		if (**line == 'r' || **line == 'b')
			pars_trian(line, scene);
		else
			exit_pars();
	}
}

void	type_id(t_scene *scene, char **line)
{
	if (**line == 'R' || **line == 'A')
		pars_ra(line, scene);
	else if (**line == 'c' || **line == 'l' || **line == 's')
		parser1(scene, line);
	else if (**line == 't' || **line == 'p')
		parser2(scene, line);
	else
		exit_pars();
}

void	parser(int fd, t_scene *scene)
{
	char	*line;
	char	*c;
	int		n;
	int		k;

	k = 0;
	while ((n = get_next_line(fd, &c)) || !k)
	{
		if (n == 0)
			k = 1;
		pure_hatred(c, n, &line);
		if (*line == '#')
		{
			free(c);
			continue;
		}
		if (*line == '\0')
			continue;
		type_id(scene, &line);
		if (!is_end(line))
			exit_pars();
		free(c);
	}
	free(c);
	correct(scene);
}
