/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:20:59 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/18 07:55:58 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 1;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static t_list	*update_s(char const **s, char c, t_list *elem)
{
	size_t	len;

	len = len_word(*s, c);
	if (!elem)
	{
		if (!(elem = ft_lstnew(ft_strsub(*s, 0, len), len + 1)))
			return (NULL);
	}
	else
	{
		if (!(elem->next = ft_lstnew(ft_strsub(*s, 0, len), len + 1)))
			return (NULL);
		elem = elem->next;
	}
	*s = *s + len - 1;
	return (elem);
}

t_list			*ft_strsplit_lst(char const *s, char c)
{
	t_list	*head;
	t_list	*elem;

	if (!s)
		return (NULL);
	head = NULL;
	while (*s)
	{
		if (*s != c)
		{
			if (!head)
			{
				if (!(head = update_s(&s, c, head)))
					return (NULL);
				elem = head;
			}
			else if (!(elem = update_s(&s, c, elem)))
				return (NULL);
		}
		s++;
	}
	if (!head)
		if (!(head = ft_lstnew(s, ft_strlen(s) + 1)))
			return (NULL);
	return (head);
}
