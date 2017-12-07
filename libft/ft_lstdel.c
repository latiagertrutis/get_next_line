/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:36:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/16 07:57:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*aux;

	aux = NULL;
	if (!alst || !del)
		return ;
	while (*alst)
	{
		aux = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = aux;
	}
}
