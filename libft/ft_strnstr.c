/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:00:54 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/03 15:59:12 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;

	i = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	if (ft_strlen(str1) >= ft_strlen(str2) && len)
	{
		while (i < len - ft_strlen(str2) + 1 && str1[i])
		{
			if (str1[i] == str2[0])
			{
				if (ft_strncmp(str1 + i, str2, ft_strlen(str2)) == 0)
					return ((char *)str1 + i);
			}
			i++;
		}
	}
	return (NULL);
}
