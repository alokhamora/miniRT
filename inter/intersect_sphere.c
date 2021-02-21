/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:13:10 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/18 18:33:07 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector	vp_mult(t_vector v, double t)
{
	t_vector	p;

	p.x = v.x * t;
	p.y = v.y * t;
	p.z = v.z * t;
	return (p);
}

void		search_t(t_int_sph *s, t_ray pack, t_sphere sphere)
{
	s->thc = sqrt(pow(sphere.diamtr / 2, 2) - s->d);
	s->t0 = s->tca - s->thc;
	s->t1 = s->tca + s->thc;
	if (s->t0 > s->t1)
	{
		pack.t = s->t1;
		s->t1 = s->t0;
		s->t0 = pack.t;
	}
	if (s->t0 < 0)
		s->t0 = s->t1;
}

int			inter_sph(t_ray pack, t_rt *rt, t_sphere *sphere)
{
	t_int_sph	s;

	s.l = vect_subtr(sphere->center, pack.view_p);
	pack.direct = normalize(pack.direct);
	s.tca = scalar_prod(s.l, pack.direct);
	if ((s.d = scalar_prod(s.l, s.l) - s.tca * s.tca) > pow(sphere->diamtr /
															2, 2))
		return (0);
	search_t(&s, pack, *sphere);
	if (s.t0 < 0)
		return (0);
	pack.t = s.t0;
	if (rt->t > pack.t)
	{
		rt->phit = vect_sum(pack.view_p, vp_mult(pack.direct, pack.t));
		rt->t = pack.t;
		rt->normal = vect_subtr(rt->phit, sphere->center);
		rt->normal = normalize(rt->normal);
		rt->color = sphere->color;
		rt->near = sphere;
	}
	return (1);
}
