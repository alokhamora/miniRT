/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:26:46 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 12:44:04 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_close g_close;

void	init_lib(t_paint *p, t_vars *var, t_data *img, t_scene *scene)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, scene->resol->width,
							scene->resol->height, "miniRT");
	img->img = mlx_new_image(var->mlx, scene->resol->width,
						scene->resol->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	p->arr = ft_calloc(sizeof(int), scene->resol->height * scene->resol->width);
	g_close.vars = var;
	g_close.arr = p->arr;
	g_close.img = img;
	if (!var->win || !var->mlx || !img->img || !p->arr || !img->addr)
		err_exit("Library initiation error :'( \n");
}

int		main(int argc, char **argv)
{
	t_data		img;
	t_vars		var;
	t_scene		*scene;
	t_paint		p;
	t_stuff		trash;

	scene = ft_calloc(1, sizeof(t_scene));
	g_close.scene = scene;
	parser(correct_arg(argc, argv), scene);
	init_lib(&p, &var, &img, scene);
	paint(p.arr, scene, &img, &var);
	if (argc == 3 && ft_angelina(argv[2], "--save"))
	{
		save_to_bmp(p.arr, *scene->resol);
		return_free(scene, p.arr);
		return (0);
	}
	mlx_hook(var.win, 17, 0, cross_but, NULL);
	p.img = &img;
	p.scene = scene;
	p.vars = var;
	trash.cam = &p;
	trash.close = &g_close;
	mlx_key_hook(var.win, key_stuff, &trash);
	mlx_loop(var.mlx);
}
