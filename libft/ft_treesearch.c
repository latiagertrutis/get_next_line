/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 00:12:07 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/05 18:48:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree		*ft_treesearch(t_tree *elem, int tree_id)
{
	if (tree_id > elem->tree_id)
	{
		while (elem->next)
		{
			elem = elem->next;
			if (elem->tree_id == tree_id)
				return (elem);
			if (tree_id < elem->tree_id)
				return (NULL);
		}
		return (NULL);
	}
	else if (tree_id < elem->tree_id)
	{
		while (elem->before)
		{
			elem = elem->before;
			if (elem->tree_id == tree_id)
				return (elem);
			if (tree_id > elem->tree_id)
				return (NULL);
		}
		return (NULL);
	}
	return (elem);
}
