/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:42:17 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/19 14:16:09 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector	normalize(t_vector vector)
{
	t_vector	new_vector;
	double		len;
	double		inv_len;

	len = vect_len(vector);
	inv_len = 1 / len;
	new_vector.x = vector.x * inv_len;
	new_vector.y = vector.y * inv_len;
	new_vector.z = vector.z * inv_len;
	return (new_vector);
}

t_matrix	look_at(t_cam cam)
{
	t_vector	tmp;
	t_vector	right;
	t_vector	up;
	t_matrix	matrix;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	right = cross_prod(normalize(tmp), cam.normal_v);
	up = cross_prod(cam.normal_v, right);
	matrix.right = right;
	matrix.up = up;
	matrix.forward = cam.normal_v;
	return (matrix);
}

t_vector	ray_direct(double x, double y, t_resol img, t_cam cam)
{
	t_vector	ray_direct;
	t_vector	pix;
	t_matrix	m;

	m = look_at(cam);
	pix.x = (1 - 2 * ((x + 0.5) / img.width)) * tan(cam.fov / 2 * M_PI / 180);
	pix.y = (1 - 2 * ((y + 0.5) / img.height)) * tan(cam.fov / 2 * M_PI /
			180) * (img.height * 1.0 / img.width);
	pix.z = 1.0;
	ray_direct.x = m.right.x * pix.x + m.up.x * pix.y + m.forward.x * pix.z;
	ray_direct.y = m.right.y * pix.x + m.up.y * pix.y + m.forward.y * pix.z;
	ray_direct.z = m.right.z * pix.x + m.up.z * pix.y + m.forward.z * pix.z;
	ray_direct = normalize(ray_direct);
	return (ray_direct);
}

t_vector	change_basis(t_vector inp, t_vector x, t_vector y, t_vector z)
{
	t_vector ret;

	ret.x = inp.x * x.x + inp.y * x.y + inp.z * x.z;
	ret.y = inp.x * y.x + inp.y * y.y + inp.z * y.z;
	ret.z = inp.x * z.x + inp.y * z.y + inp.z * z.z;
	return (ret);
}

t_vector	return_basis(t_vector inp, t_vector x, t_vector y, t_vector z)
{
	t_vector ret;

	ret.x = inp.x * x.x + inp.y * y.x + inp.z * z.x;
	ret.y = inp.x * x.y + inp.y * y.y + inp.z * z.y;
	ret.z = inp.x * x.z + inp.y * y.z + inp.z * z.z;
	return (ret);
}
