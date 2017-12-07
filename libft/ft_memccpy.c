/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:37:57 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/13 23:24:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*s1;
	const char			*s2;
	size_t				i;
	char				ch;

	ch = c;
	s1 = (char *)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
