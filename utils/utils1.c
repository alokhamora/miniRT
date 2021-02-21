/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:53:03 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/21 12:41:32 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		create_trgb(t_color *color)
{
	return ((int)(color->red * 255) << 16 | (int)(color->green * 255) << 8 |
			(int)(color->blue * 255));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		correct_filename(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str) - 3;
	if (str[i] == '.' && str[i + 1] == 'r' && str[i + 2] == 't')
		return (1);
	return (0);
}

int		correct_arg(int argc, char **argv)
{
	int fd;

	if (argc < 2)
		exit_pars();
	if (argc > 3)
		exit_pars();
	if (argc == 3 && !ft_angelina(argv[2], "--save"))
		exit_pars();
	if (!correct_filename(argv[1]))
		exit_pars();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Unknown file");
	return (fd);
}
