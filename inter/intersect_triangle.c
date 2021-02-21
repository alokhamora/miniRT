/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:41:25 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 17:28:38 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	search_det(t_int_tr *t, t_ray pack, t_trian trian)
{
	t->a = vect_subtr(trian.sp, trian.fp);
	t->b = vect_subtr(trian.tp, trian.fp);
	t->pvec = cross_prod(pack.direct, t->b);
	t->det = scalar_prod(t->a, t->pvec);
}

void	write_rt(t_rt *rt, t_trian *trian, t_ray pack, t_int_tr t)
{
	t_color		tmp;
	t_color		tmp1;
	t_color		tmp2;

	rt->t = scalar_prod(t.b, t.qvec) / t.det;
	if (trian->id == 'r')
	{
		tmp = pcolr_mult(t.u, trian->color[0]);
		tmp1 = pcolr_mult(t.v, trian->color[1]);
		tmp2 = pcolr_mult((1 - t.u - t.v), trian->color[2]);
		rt->color = color_sum(color_sum(tmp, tmp1), tmp2);
	}
	if (trian->id == 't')
		rt->color = trian->color[0];
	rt->normal = normalize(cross_prod(t.b, t.a));
	if (scalar_prod(rt->normal, pack.direct) > 0)
		rt->normal = vp_mult(rt->normal, -1);
	pack.direct = normalize(pack.direct);
	rt->phit = vect_sum(pack.view_p, vp_mult(pack.direct, rt->t));
	rt->phit = vect_sum(rt->phit, vp_mult(rt->normal, 1e-4));
	rt->near = trian;
}

int		inter_trian(t_ray pack, t_rt *rt, t_trian *trian)
{
	t_int_tr	t;

	search_det(&t, pack, *trian);
	if (fabs(t.det) < 1e-8)
		return (0);
	t.tvec = vect_subtr(pack.view_p, trian->fp);
	t.u = scalar_prod(t.tvec, t.pvec) / t.det;
	if (t.u < 0 || t.u > 1)
		return (0);
	t.qvec = cross_prod(t.tvec, t.a);
	t.v = scalar_prod(t.qvec, pack.direct) / t.det;
	if (t.v < 0 || t.u + t.v > 1)
		return (0);
	if ((scalar_prod(t.b, t.qvec) / t.det) < 0)
		return (0);
	if ((scalar_prod(t.b, t.qvec) / t.det) < rt->t)
		write_rt(rt, trian, pack, t);
	return (1);
}
