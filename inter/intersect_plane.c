/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:31:36 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/16 18:07:49 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		inter_plane(t_ray pack, t_rt *rt, t_plane plane)
{
	double		divid;
	t_vector	start;

	divid = scalar_prod(vp_mult(plane.normal_v, -1), pack.direct);
	if (fabs(divid) > 1e-6)
	{
		start = vect_subtr(plane.coord, pack.view_p);
		pack.t = scalar_prod(start, plane.normal_v) / -divid;
		if (pack.t >= 0)
		{
			if (pack.t < rt->t)
			{
				rt->t = pack.t;
				rt->color = plane.color;
				rt->normal = plane.normal_v;
				rt->phit = vect_sum(pack.view_p, vp_mult(pack.direct, pack.t));
				rt->near = &plane;
			}
			return (1);
		}
	}
	return (0);
}

int		inter_disk(t_ray pack, t_rt *rt, t_disk *disk)
{
	t_plane		pl;
	t_vector	p;
	t_vector	v;
	t_rt		tmp;

	tmp.t = INFINITY;
	pl.normal_v = disk->normal_v;
	pl.coord = disk->center;
	if (inter_plane(pack, &tmp, pl))
	{
		p = vect_sum(pack.view_p, vp_mult(pack.direct, tmp.t));
		v = vect_subtr(p, disk->center);
		if (vect_len(v) <= disk->diamtr / 2)
		{
			if (rt->t > tmp.t)
			{
				*rt = tmp;
				rt->color = disk->color;
				rt->phit = vect_sum(pack.view_p, vp_mult(pack.direct, rt->t));
				rt->near = disk;
			}
			return (1);
		}
	}
	return (0);
}
