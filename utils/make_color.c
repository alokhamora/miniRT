/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:09:22 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/19 12:28:05 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color		color_sum(t_color color1, t_color color2)
{
	t_color		res;

	res.red = color1.red + color2.red;
	res.green = color1.green + color2.green;
	res.blue = color1.blue + color2.blue;
	return (res);
}

t_color		pcolr_mult(double i, t_color color)
{
	t_color res;

	res.red = color.red * i > 1 ? 1 : color.red * i;
	res.green = color.green * i > 1 ? 1 : color.green * i;
	res.blue = color.blue * i > 1 ? 1 : color.blue * i;
	return (res);
}

t_color		color_mask(t_color c1, t_color c2)
{
	t_color ret;

	ret.red = c1.red * c2.red;
	ret.blue = c1.blue * c2.blue;
	ret.green = c1.green * c2.green;
	return (ret);
}

void		make_color1(t_make_col *m, t_rt rt, t_obj obj, t_color *c)
{
	t_vector			e;
	t_vector			v;
	t_vector			l;
	double				cos1;
	int					i;

	e = normalize(vect_subtr(m->cam.view_p, m->pack.view_p));
	l = normalize(vect_subtr(m->c->coord, m->pack.view_p));
	v = normalize(vect_sum(e, l));
	cos1 = pow(scalar_prod(v, rt.normal), 100);
	m->pack.direct = normalize(vect_subtr(m->c->coord, rt.phit));
	m->cos = scalar_prod(rt.normal, m->pack.direct);
	m->cos = m->cos < 0 ? 0 : m->cos;
	m->len = vect_len(vect_subtr(m->c->coord, rt.phit));
	m->tmp1.t = INFINITY;
	i = intersection(m->pack, obj, &m->tmp1);
	if (!(rt.near != m->tmp1.near && i) || m->tmp1.t >= m->len)
	{
		m->tmp = pcolr_mult(m->cos, rt.color);
		m->tmp = color_mask(m->c->color, color_mask(m->tmp, rt.color));
		*c = color_sum(m->tmp, *c);
		*c = color_sum(pcolr_mult(cos1, m->c->color), *c);
	}
}

t_color		make_color(t_rt rt, t_light light, t_obj obj, t_cam cam)
{
	t_make_col		m;
	t_color			color;

	m.cam = cam;
	m.c = &light;
	color = color_mask(rt.color, light.ambient);
	m.pack.view_p = vect_sum(rt.phit, vp_mult(rt.normal, 1e-4));
	while (m.c)
	{
		make_color1(&m, rt, obj, &color);
		m.c = m.c->next;
	}
	color.red = color.red > 1 ? 1 : color.red;
	color.green = color.green > 1 ? 1 : color.green;
	color.blue = color.blue > 1 ? 1 : color.blue;
	return (color);
}
