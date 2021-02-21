/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:44:55 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/16 17:32:44 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		intersection1(t_ray pack, t_obj obj, t_rt *rt, int i)
{
	if (obj.cyl == 1)
	{
		while (obj.clndr)
		{
			if (inter_cyl(pack, rt, obj.clndr))
				i = 1;
			obj.clndr = obj.clndr->next;
		}
	}
	if (obj.sqr == 1)
	{
		while (obj.square)
		{
			if (inter_square(pack, rt, *obj.square))
				i = 1;
			obj.square = obj.square->next;
		}
	}
	return (i);
}

int		intersection2(t_ray pack, t_obj obj, t_rt *rt, int i)
{
	if (obj.sph == 1)
	{
		while (obj.sphere)
		{
			if (inter_sph(pack, rt, obj.sphere))
				i = 1;
			obj.sphere = obj.sphere->next;
		}
	}
	if (obj.pl == 1)
	{
		while (obj.plane)
		{
			if (inter_plane(pack, rt, *obj.plane))
				i = 1;
			obj.plane = obj.plane->next;
		}
	}
	return (i);
}

int		intersection(t_ray pack, t_obj obj, t_rt *rt)
{
	int		i;

	i = 0;
	if (obj.tr == 1)
	{
		while (obj.trian)
		{
			if (inter_trian(pack, rt, obj.trian))
				i = 1;
			obj.trian = obj.trian->next;
		}
	}
	if ((obj.pl == 1) || (obj.sph == 1))
		i = intersection2(pack, obj, rt, i);
	if ((obj.cyl == 1) || (obj.sqr == 1))
		i = intersection1(pack, obj, rt, i);
	return (i);
}
