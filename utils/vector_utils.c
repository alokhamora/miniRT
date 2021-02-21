/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:06 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/18 13:49:03 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector	vect_sum(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vector	cross_prod(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vector	vect_subtr(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

double		scalar_prod(t_vector a, t_vector b)
{
	double c;

	c = a.x * b.x + a.y * b.y + a.z * b.z;
	return (c);
}

double		vect_len(t_vector vector)
{
	double l;

	l = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	return (l);
}
