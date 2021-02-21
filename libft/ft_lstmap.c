/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:15:21 by mchaya            #+#    #+#             */
/*   Updated: 2020/11/07 14:45:54 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *s;
	t_list *d;

	d = 0;
	while (lst && f)
	{
		if (!(s = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&d, del);
			return (0);
		}
		ft_lstadd_back(&d, s);
		lst = lst->next;
	}
	return (d);
}
