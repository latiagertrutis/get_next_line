/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:23:46 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/17 01:07:10 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**p_str_reall(char **p_str, size_t p_len)
{
	size_t	len;
	char	**p_aux;

	len = 0;
	p_aux = (char **)malloc(sizeof(char *) * (p_len + 2));
	if (!p_aux)
		return (NULL);
	while (len < p_len)
	{
		p_aux[len] = p_str[len];
		p_str[len] = NULL;
		len++;
	}
	p_aux[len++] = NULL;
	p_aux[len] = NULL;
	free(p_str);
	p_str = NULL;
	return (p_aux);
}

static int		len_word(char const *s, char c)
{
	size_t	len;

	len = 1;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p_str;
	size_t	p_len;

	if (!s)
		return (NULL);
	if (!(p_str = (char **)malloc(sizeof(char*))))
		return (NULL);
	p_str[0] = NULL;
	p_len = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!(p_str = p_str_reall(p_str, p_len)))
				return (NULL);
			p_len++;
			p_str[p_len - 1] = ft_strsub(s, 0, len_word(s, c));
			s = s + len_word(s, c);
		}
		else
			s++;
	}
	return (p_str);
}
