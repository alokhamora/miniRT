/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:03:11 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/20 15:05:46 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_light(t_light *light)
{
	t_light *tmp;

	while (light)
	{
		tmp = light->next;
		free(light);
		light = tmp;
	}
}

void	free_trian(t_trian *trian)
{
	t_trian *tmp;

	while (trian)
	{
		tmp = trian->next;
		free(trian->color);
		free(trian);
		trian = tmp;
	}
}

void	free_sphere(t_sphere *sphere)
{
	t_sphere *tmp;

	while (sphere)
	{
		tmp = sphere->next;
		free(sphere);
		sphere = tmp;
	}
}

void	free_square(t_square *square)
{
	t_square *tmp;

	while (square)
	{
		tmp = square->next;
		free(square);
		square = tmp;
	}
}

void	free_clndr(t_clndr *clndr)
{
	t_clndr *tmp;

	while (clndr)
	{
		tmp = clndr->next;
		free(clndr);
		clndr = tmp;
	}
}
