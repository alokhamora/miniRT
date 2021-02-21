/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:21:42 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/04 18:39:38 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ispositive(char n)
{
	if (n == 45)
		return (-1);
	if (n == 43)
		return (1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	k;
	int		n;

	i = 0;
	k = 0;
	n = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		n = ispositive(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - '0');
		i++;
		if (k > 2147483647 && n == 1)
			return (-1);
		if (k > 2147483648 && n == -1)
			return (0);
	}
	k *= n;
	return (k);
}
