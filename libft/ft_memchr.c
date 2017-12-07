/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:26:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/10 21:43:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char		*s;
	char		ch;
	size_t		i;

	s = (char *)str;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	return (NULL);
}
