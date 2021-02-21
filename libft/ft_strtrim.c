/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:34:58 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/04 17:16:58 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		char_in_set(char s, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_count(int s, int i)
{
	if (s == -1)
		return (0);
	return (s - i + 1);
}

static char		*make_trim(char *trim, char const *s1, int s, int count)
{
	int i;

	i = 0;
	while (count > s)
	{
		trim[s] = s1[i];
		s++;
		i++;
	}
	return (trim);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		s;
	int		count;

	i = 0;
	if (!s1)
		return (0);
	while (char_in_set(s1[i], set) == 1)
		i++;
	s = ft_strlen(s1) - 1;
	while (s >= 0 && char_in_set(s1[s], set) == 1)
		s--;
	count = ft_count(s, i);
	trim = malloc(count + 1);
	if (!trim)
		return (NULL);
	s = 0;
	if (count > s)
		trim = make_trim(trim, s1 + i, s, count);
	trim[count] = '\0';
	return (trim);
}
