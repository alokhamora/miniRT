/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:40:23 by mchaya            #+#    #+#             */
/*   Updated: 2021/02/16 18:10:11 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int				ft_atod(char *str, double *d)
{
	double	k;
	int		s;

	s = 1;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	*d = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		k = 0.1;
		while (*str && *str >= '0' && *str <= '9')
		{
			*d += k * (*str - '0');
			k *= 0.1;
			str++;
		}
	}
	*d = *d * s;
	return (1);
}
