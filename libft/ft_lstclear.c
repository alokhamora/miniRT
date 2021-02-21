/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:02:53 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/07 13:14:03 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *s;

	if (!(lst && *lst && del))
		return ;
	while (lst && *lst)
	{
		s = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = s;
	}
}
