/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:33:52 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/16 23:05:21 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*len_int(int n, size_t *p_len)
{
	char			*str;

	if (n < 0)
	{
		while (n <= -10)
		{
			(*p_len)++;
			n = n / 10;
		}
		(*p_len)++;
	}
	else
	{
		while (n >= 10)
		{
			(*p_len)++;
			n = n / 10;
		}
	}
	(*p_len)++;
	if (!(str = (char *)malloc(sizeof(char) * (*p_len + 1))))
		return (NULL);
	str[*p_len] = '\0';
	(*p_len)--;
	return (str);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = 0;
	if (!(str = len_int(n, &len)))
		return (NULL);
	if (n < 0)
	{
		while (n <= -10)
		{
			str[len--] = -(n % 10) + 48;
			n = n / 10;
		}
		str[len--] = -n + 48;
		str[len] = '-';
		return (str);
	}
	while (n >= 10)
	{
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	str[len] = n + 48;
	return (str);
}
