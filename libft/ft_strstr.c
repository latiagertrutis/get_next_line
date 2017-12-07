/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:40 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/11 22:38:46 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	size_t	i;
	size_t	len;

	hay = (char *)haystack;
	len = ft_strlen(needle);
	if (!len)
		return (hay);
	while (*hay)
	{
		i = 0;
		while (i < len)
		{
			if (hay[i] != needle[i])
				i = len;
			else
			{
				i++;
				if (i == len)
					return (hay);
			}
		}
		hay++;
	}
	return (NULL);
}
