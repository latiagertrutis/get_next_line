/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:40:01 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/15 00:58:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (i);
		i++;
	}
	return (i);
}

static unsigned int	ft_end(char const *s)
{
	unsigned int	i;

	i = (unsigned int)ft_strlen(s) - 1;
	while (i != 0)
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (i + 1);
		i--;
	}
	return (i + 1);
}

char				*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	i = 0;
	start = ft_start(s);
	if (!start && (!*s || *s == ' ' || *s == '\n' || *s == '\t'))
		return (ft_strnew(1));
	end = ft_end(s);
	return (ft_strsub(s, start, end - start));
}
