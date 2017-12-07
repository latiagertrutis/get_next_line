/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:45:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/17 00:21:55 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t max)
{
	char	*hay;
	size_t	i;
	size_t	len;

	hay = (char *)haystack;
	if (!(len = ft_strlen(needle)))
		return (hay);
	while (*hay && max)
	{
		i = 0;
		while (i < len && i < max)
		{
			if (hay[i] != needle[i])
				i = len;
			else
			{
				if (++i == len)
					return (hay);
			}
		}
		hay++;
		if (!(--max))
			return (NULL);
	}
	return (NULL);
}
