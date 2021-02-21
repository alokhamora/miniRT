/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:40:33 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/25 16:50:55 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*str;

	i = 0;
	b = 0;
	if (!s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b])
		str[i++] = s2[b++];
	free((void *)s1);
	str[i] = '\0';
	return (str);
}

int		ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int		i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		l;

	l = ft_strlen(s1) + 1;
	s2 = malloc(l);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, l);
	return (s2);
}
