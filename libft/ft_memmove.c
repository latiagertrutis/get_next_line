/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:33:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/13 22:28:01 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = (char *)str1;
	s2 = (const char *)str2;
	if (str1 < str2)
	{
		i = 0;
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else if (str1 != str2)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			s1[i] = s2[i];
			i--;
		}
	}
	return (str1);
}
