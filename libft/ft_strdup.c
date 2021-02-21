/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:57 by mchaya            #+#    #+#             */
/*   Updated: 2020/10/30 03:58:14 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l;

	l = ft_strlen(s1) + 1;
	s2 = malloc(l);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, l);
	return (s2);
}
