/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:46 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 12:57:34 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		inter_square(t_ray pack, t_rt *rt, t_square square)
{
	t_plane		plane;
	t_vector	v;
	t_vector	phit;
	t_rt		tmp;

	plane.coord = square.center;
	plane.normal_v = square.normal_v;
	tmp.t = INFINITY;
	if (inter_plane(pack, &tmp, plane))
	{
		phit = vect_sum(pack.view_p, vp_mult(pack.direct, tmp.t));
		v = vect_subtr(tmp.phit, square.center);
		if (fabs(v.x) > square.size / 2 || fabs(v.y) > square.size / 2 ||
		fabs(v.z) > square.size / 2)
			return (0);
		if (rt->t > tmp.t)
		{
			*rt = tmp;
			rt->phit = phit;
			rt->color = square.color;
			rt->near = &square;
		}
		return (1);
	}
	return (0);
}
