/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:05:03 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/05 12:24:43 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *s;

	s = malloc(sizeof(t_list));
	if (!s)
		return (0);
	s->content = content;
	s->next = 0;
	return (s);
}
