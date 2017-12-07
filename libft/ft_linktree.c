/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linktree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 01:43:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/04 01:43:29 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_linktree(t_tree *tree, t_tree *new)
{
	if (new->tree_id > tree->tree_id)
	{
		while (tree->next)
		{
			if(new->tree_id < tree->next->tree_id)
			{
				new->next = tree->next;
				new->before = tree;
				tree->next = new;
				return (new);
			}
			tree = tree->next;
		}
		tree->next = new;
		new->before = tree;
		return (new);
	}
	while (tree->before)
	{
		if(new->tree_id > tree->before->tree_id)
		{
			new->before = tree->before;
			new->next = tree;
			tree->before = new;
			return (new);
		}
		tree = tree->before;
	}
	tree->before = new;
	new->next = tree;
	return (new);
}
