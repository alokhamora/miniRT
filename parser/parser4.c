/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:45:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 14:26:40 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	err_exit(char *line)
{
	ft_putstr_fd("Error\n", 2);
	if (line)
		ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	return_free(g_close.scene, g_close.arr);
	exit(1);
}

void	exit_pars(void)
{
	ft_putstr_fd("Error\nPars error\n", 2);
	return_free(g_close.scene, g_close.arr);
	exit(1);
}

void	pars_trian1(t_trian *tmp, char **line)
{
	if (**line == 'r')
	{
		tmp->id = 't';
		tmp->color = ft_calloc(1, sizeof(t_color));
	}
	else if (**line == 'b')
	{
		tmp->id = 'r';
		tmp->color = ft_calloc(3, sizeof(t_color));
	}
	else
		exit_pars();
	(*line)++;
	tmp->fp = get_vector(line);
	tmp->sp = get_vector(line);
	tmp->tp = get_vector(line);
	tmp->color[0] = get_color(line);
}

int		pars_trian(char **line, t_scene *scene)
{
	t_trian *tmp;
	t_trian *ext;

	if (!(tmp = ft_calloc(1, sizeof(t_trian))))
		err_exit("Memory allocation error");
	pars_trian1(tmp, line);
	scene->obj.tr = 1;
	if (tmp->id == 'r')
	{
		tmp->color[1] = get_color(line);
		tmp->color[2] = get_color(line);
	}
	ext = scene->obj.trian;
	if (ext == NULL)
	{
		scene->obj.trian = tmp;
		return (0);
	}
	while (ext->next)
		ext = ext->next;
	ext->next = tmp;
	return (1);
}

void	pure_hatred(char *c, int n, char **line)
{
	*line = c;
	if (n < 0)
		exit_pars();
	while (**line == ' ' || **line == '\t')
		(*line)++;
}
