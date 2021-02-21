/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:18:47 by mchaya            #+#    #+#             */
/*   Updated: 2020/10/28 14:48:21 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	k;
	unsigned char	*d;

	k = (unsigned char)c;
	i = 0;
	d = (unsigned char *)b;
	while (i < len)
	{
		d[i] = k;
		i++;
	}
	return (d);
}
