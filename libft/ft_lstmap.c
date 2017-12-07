/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:11:19 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/16 09:10:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	if (!(elem = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size)))
		return (NULL);
	head = elem;
	lst = lst->next;
	while (lst)
	{
		if (!(elem->next =
					ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size)))
			return (NULL);
		elem = elem->next;
		lst = lst->next;
	}
	return (head);
}
