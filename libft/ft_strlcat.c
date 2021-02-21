/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:26:27 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/04 17:41:33 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t k;
	size_t l;
	size_t i;

	k = 0;
	i = 0;
	l = ft_strlen(dst);
	if (size == 0 || l > size)
		return (ft_strlen(src) + size);
	if (size)
	{
		while (dst[i])
			i++;
		while (src[k] && i < size - 1)
		{
			dst[i] = src[k];
			i++;
			k++;
		}
	}
	dst[i] = '\0';
	return (l + ft_strlen(src));
}
