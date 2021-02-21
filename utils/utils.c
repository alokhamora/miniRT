/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:36:21 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 09:49:24 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_close(int keycode)
{
	if (keycode == 53)
	{
		return_free(g_close.scene, g_close.arr);
		mlx_destroy_window(g_close.vars->mlx, g_close.vars->win);
		mlx_destroy_image(g_close.vars->mlx, g_close.img->img);
		exit(0);
	}
	return (0);
}

int		cross_but(void *ptr)
{
	ptr = NULL;
	return_free(g_close.scene, g_close.arr);
	exit(0);
	return (0);
}

int		cam_change(int keycode, t_stuff *p)
{
	if (keycode == 49)
		p->cam->scene->cam = p->cam->scene->cam->next;
	paint(p->cam->arr, p->cam->scene, p->cam->img, p->close->vars);
	return (0);
}

int		key_stuff(int key_num, t_stuff *a)
{
	if (key_num == 53)
		ft_close(key_num);
	else if (key_num == 49)
		cam_change(key_num, a);
	else
		return (0);
	return (0);
}

int		paint(int *arr, t_scene *scene, t_data *img, t_vars *v)
{
	int			x;
	int			y;
	t_ray		pack;
	t_rt		rt;
	t_color		color;

	y = -1;
	pack.view_p = scene->cam->view_p;
	while (++y < scene->resol->height)
	{
		x = -1;
		while (++x < scene->resol->width)
		{
			pack.direct = ray_direct(x, y, *scene->resol, *scene->cam);
			rt.t = INFINITY;
			color = (t_color){0, 0, 0};
			if (intersection(pack, scene->obj, &rt) && scene->light)
				color = make_color(rt, *scene->light, scene->obj, *scene->cam);
			arr[y * scene->resol->width + x] = create_trgb(&color);
			my_mlx_pixel_put(img, x, y, arr[y * scene->resol->width + x]);
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, img->img, 0, 0);
	return (1);
}
