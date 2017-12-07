/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:53:27 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/11 20:49:06 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	while (i < size)
	{
		if (!dst[i])
		{
			while ((i < (size - 1)) && src[j])
				dst[i++] = src[j++];
			dst[i] = '\0';
			return (i - j + len);
		}
		i++;
	}
	return (size + ft_strlen(src));
}
