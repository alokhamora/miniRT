/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:17:11 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/19 15:18:54 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double		value_t(double t1, double t2)
{
	double t;

	t = (t1 < t2) ? t1 : t2;
	if (t < 0)
		t = (t1 > t2) ? t1 : t2;
	return (t);
}

void		calc_t(t_int_cyl *c, t_clndr cyl, t_ray ray)
{
	t_ray	tmp;

	c->x = make_right(cyl.normal_v);
	cyl.normal_v = normalize(cyl.normal_v);
	c->y = cross_prod(c->x, cyl.normal_v);
	c->q.direct = change_basis(ray.direct, c->x, c->y, cyl.normal_v);
	c->q.view_p = change_basis(vect_subtr(ray.view_p, cyl.coord)
			, c->x, c->y, cyl.normal_v);
	tmp = c->q;
	tmp.direct.z = 0;
	c->a = pow(c->q.direct.x, 2) + pow(c->q.direct.y, 2);
	c->b = 2 * (c->q.direct.x * c->q.view_p.x + c->q.direct.y * c->q.view_p.y);
	c->c = pow(c->q.view_p.x, 2) + pow(c->q.view_p.y, 2) -
			pow((cyl.diamtr / 2), 2);
	c->pack.t = solve_qd(c->a, c->b, c->c);
}

void		rec_rt(t_rt *rt, t_clndr *cyl, t_ray ray, t_int_cyl c)
{
	rt->color = cyl->color;
	rt->near = cyl;
	rt->t = c.pack.t;
	rt->phit = vect_sum(vp_mult(ray.direct, c.pack.t), ray.view_p);
}

void		make_z(t_clndr *cyl, t_int_cyl *c)
{
	if (cyl->normal_v.z == 0)
		c->x.z = 1;
	else
		c->x.z = 0;
	cyl->normal_v = normalize(cyl->normal_v);
}

int			inter_cyl(t_ray ray, t_rt *rt, t_clndr *cyl)
{
	t_int_cyl	c;
	t_vector	pt;
	int			k;

	c.x = cyl->normal_v;
	make_z(cyl, &c);
	if (search_disk(ray, rt, *cyl))
		k = 1;
	calc_t(&c, *cyl, ray);
	if (c.pack.t < 0)
		return (0);
	pt = vect_sum(c.q.view_p, vp_mult(c.q.direct, c.pack.t));
	if (pt.z < 0 || pt.z > cyl->height)
		return (0);
	pt.z = 0;
	if (c.pack.t < rt->t)
	{
		rt->normal = normalize(return_basis(pt, c.x, c.y, cyl->normal_v));
		rec_rt(rt, cyl, ray, c);
		return (1);
	}
	if (k)
		return (1);
	return (0);
}
