/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search_by_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:44:25 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/01 22:27:22 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_search_by_size(t_list *head, size_t content_size)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->content_size == content_size)
			return (head);
		head = head->next;
	}
	return (NULL);
}
