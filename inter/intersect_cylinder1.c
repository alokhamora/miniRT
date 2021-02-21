/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:15:48 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/19 15:18:54 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double		solve_qd(double a, double b, double c)
{
	double	dscr;
	double	ret;
	double	x1;
	double	x2;

	ret = 0;
	dscr = b * b - 4 * a * c;
	if (dscr < 0)
		return (-1);
	x1 = (-b + sqrt(dscr)) / (2 * a);
	x2 = (-b - sqrt(dscr)) / (2 * a);
	if (x1 >= x2 - 1e-3 && x1 <= x2 + 1e-3 && x1 > 0)
		return (x1);
	if (x1 >= x2)
		ret = x2;
	if (ret <= 0)
		ret = x1;
	if (ret < 0)
		return (-1);
	return (ret);
}

t_vector	make_right(t_vector x)
{
	t_vector t;
	t_vector ret;

	t.x = 0;
	t.y = -1;
	t.z = 0;
	if (x.y == 1)
		x.x = 0.00001;
	if (x.y == -1)
		x.x = 0.00001;
	x = normalize(x);
	ret = cross_prod(x, t);
	ret = normalize(ret);
	return (ret);
}

int			search_disk(t_ray ray, t_rt *rt, t_clndr cyl)
{
	t_disk *d1;
	t_disk *d2;

	d1 = ft_calloc(sizeof(t_disk), 1);
	d2 = ft_calloc(sizeof(t_disk), 1);
	d1->center = cyl.coord;
	d1->normal_v = vp_mult(cyl.normal_v, -1);
	d1->color = cyl.color;
	d1->diamtr = cyl.diamtr;
	d2->center = vect_sum(cyl.coord, vp_mult(cyl.normal_v, cyl.height));
	d2->normal_v = cyl.normal_v;
	d2->color = cyl.color;
	d2->diamtr = cyl.diamtr;
	if (inter_disk(ray, rt, d1) || inter_disk(ray, rt, d2))
	{
		free(d1);
		free(d2);
		return (1);
	}
	free(d1);
	free(d2);
	return (0);
}
