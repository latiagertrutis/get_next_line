/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newleaf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:05:26 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/03 20:27:51 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_newleaf(void const *content, size_t content_size, int tree_id)
{
	t_tree	*new_tree;

	if (!(new_tree = (t_tree *)ft_memalloc(sizeof(t_tree))))
		return (NULL);
	if (content)
	{
		if (!(new_tree->content = (void *)ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new_tree->content, content, content_size);
		new_tree->content_size = content_size;
		new_tree->tree_id = tree_id;
	}
	else
	{
		new_tree->content = NULL;
		new_tree->content_size = 0;
		new_tree->tree_id = tree_id;
	}
	new_tree->next = NULL;
	new_tree->before = NULL;
	return (new_tree);
}
