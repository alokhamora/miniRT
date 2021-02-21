/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:50:00 by mchaya            #+#    #+#             */
/*   Updated: 2020/10/29 10:45:22 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
