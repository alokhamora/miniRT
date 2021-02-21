/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:16:56 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 16:17:56 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	write_head(int fd, t_resol r, int size)
{
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = 0;
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = 54;
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = 40;
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = r.width;
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = r.height;
	if ((write(fd, &size, 4)) < 0)
		err_exit("Screen error");
	size = 1;
	if ((write(fd, &size, 2)) < 0)
		err_exit("Screen error");
	size = 32;
	if ((write(fd, &size, 2)) < 0)
		err_exit("Screen error");
}

void	write1(int fd)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (i++ < 6)
		if ((write(fd, &size, 4)) < 0)
			err_exit("Screen error");
}

int		save_to_bmp(int *arr, t_resol r)
{
	int fd;
	int size;
	int x;
	int y;

	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((write(fd, "BM", 2)) < 0)
		err_exit("Screen error");
	size = r.height * r.width * 4 + 54;
	write_head(fd, r, size);
	write1(fd);
	y = r.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < r.width)
		{
			if ((write(fd, arr + y * r.width + x, 4)) < 0)
				err_exit("Screen error");
			x++;
		}
		y--;
	}
	return (0);
}
