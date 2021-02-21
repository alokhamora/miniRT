/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:42:59 by mchaya            #+#    #+#             */
/*   Updated: 2020/10/31 15:55:55 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;

	i = 0;
	k = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			k = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	if (k == -1)
		return (NULL);
	return ((char *)s + k);
}
