/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:37:56 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/18 14:00:22 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		make_line(char **new, char **line)
{
	char *tmp;
	char *n;

	if (!ft_strchr(*new, '\n'))
	{
		if (!(*line = (*new ? ft_strdup(*new) : ft_strdup(""))))
		{
			free(*new);
			*new = 0;
			return (-1);
		}
		free(*new);
		*new = 0;
		return (0);
	}
	n = ft_strchr(*new, '\n');
	*n = '\0';
	*line = ft_strdup(*new);
	tmp = *new;
	*new = ft_strdup(++n);
	free(tmp);
	return (1);
}

int		free_next(char *next)
{
	free(next);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*new[15000];
	char			*next;
	int				r;

	if (!(next = malloc(BUFFER_SIZE + 1)) ||
			fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (free_next(next));
	while (!(ft_strchr(new[fd], '\n')) && (r = read(fd, next, BUFFER_SIZE)))
	{
		if (r == -1)
			return (free_next(next));
		next[r] = 0;
		if (!(new[fd] = ft_strjoin(new[fd], next)))
		{
			free(new[fd]);
			return (free_next(next));
		}
	}
	free(next);
	return (make_line(&new[fd], line));
}
