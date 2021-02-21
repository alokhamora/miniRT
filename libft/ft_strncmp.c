/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:04:57 by mchaya            #+#    #+#             */
/*   Updated: 2020/10/31 16:31:28 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n && (d1[i] || d2[i]))
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
		n--;
	}
	return (0);
}
