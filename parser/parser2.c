/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:35:16 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/18 14:16:04 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			get_int(char **l, int comma)
{
	char *line;
	char *c;

	line = *l;
	while (*line == ' ' || *line == '\t')
		line++;
	c = line;
	if (*line == '-')
	{
		line++;
	}
	while (ft_isdigit(*line))
		line++;
	if (!(*line == ' ' || *line == '\n' || *line == '\t' || *line == '\0' ||
	(*line == ',' && comma == 1)))
		exit_pars();
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == ',' && comma == 1)
	{
		*l = line + 1;
		return (ft_atoi(c));
	}
	*l = line;
	return (ft_atoi(c));
}

double		get_double1(char **l, char *line, int comma, char *c)
{
	double d;

	if (!(*line == ' ' || *line == '\t' || (*line == ',' && comma == 1)))
		exit_pars();
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == ',' && comma == 1)
	{
		*l = line + 1;
		ft_atod(c, &d);
		return (d);
	}
	*l = line;
	ft_atod(c, &d);
	return (d);
}

double		get_double(char **l, int comma)
{
	char	*line;
	char	*c;
	int		is_dot;
	double	d;
	int		sign;

	sign = 1;
	is_dot = 1;
	line = *l;
	while (*line == ' ' || *line == '\t')
		line++;
	c = line;
	if (*line == '-')
	{
		sign = 1;
		line++;
	}
	while (ft_isdigit(*line) || (is_dot && *line == '.'))
	{
		if (*line == '.')
			is_dot = 0;
		line++;
	}
	d = get_double1(l, line, comma, c);
	return (d * sign);
}

t_color		get_color(char **line)
{
	int		r;
	int		g;
	int		b;
	t_color ret;

	r = get_int(line, 1);
	g = get_int(line, 1);
	b = get_int(line, 0);
	ret.red = r / 255.0;
	ret.green = g / 255.0;
	ret.blue = b / 255.0;
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		exit_pars();
	return (ret);
}

t_vector	get_vector(char **line)
{
	t_vector	ret;

	ret.x = get_double(line, 1);
	ret.y = get_double(line, 1);
	ret.z = get_double(line, 0);
	return (ret);
}
