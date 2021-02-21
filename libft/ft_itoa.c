/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:25:28 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/04 12:09:46 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		num_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int		is_negative(char *num, int n)
{
	num[0] = '-';
	if (n == -2147483648)
	{
		num[1] = '2';
		n = -147483648;
	}
	return (-n);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*num;

	i = num_length(n);
	if (!(num = malloc(i + 1)))
		return (NULL);
	if (n < 0)
		n = is_negative(num, n);
	num[i] = '\0';
	i--;
	if (n == 0)
		num[i] = '0';
	while (n != 0)
	{
		num[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (num);
}
