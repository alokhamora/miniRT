/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:46:02 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/10 13:03:14 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_str(char const *s, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			n++;
			while (s[i] == c && s[i + 1])
				i++;
		}
		if (s[i + 1] == '\0' && s[i] != c)
			n++;
		i++;
	}
	return (n);
}

static int		str_length(char const *s, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

char			**make_arr(char **arr, char const *s, int i, char c)
{
	int k;
	int f;

	k = 0;
	while (k < count_str(s, c))
	{
		if (!(arr[k] = malloc(str_length(s + i, c) + 1)))
		{
			k--;
			while (k >= 0)
			{
				free(arr[k]);
				arr[k--] = 0;
			}
			free(arr);
			return (0);
		}
		f = 0;
		while (s[i] != c && s[i])
			arr[k][f++] = s[i++];
		arr[k++][f] = '\0';
		while (s[i] == c && s[i])
			i++;
	}
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	int		f;
	char	**arr;

	i = 0;
	f = 0;
	if (!s)
		return (NULL);
	l = count_str(s, c);
	if (!(arr = malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	arr[l] = 0;
	arr = make_arr(arr, s, i, c);
	return (arr);
}
