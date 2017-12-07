/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:06 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/16 23:44:14 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t n)
{
	unsigned char	c;
	size_t			i;
	unsigned char	*aux;

	aux = (unsigned char *)dest;
	c = (unsigned char)ch;
	i = 0;
	while (i < n)
		aux[i++] = c;
	return (dest);
}
