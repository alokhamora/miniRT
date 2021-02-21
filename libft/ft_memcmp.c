/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:41:20 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/03 13:51:36 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	a1 = (unsigned char *)arr1;
	a2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
	}
	return (0);
}
