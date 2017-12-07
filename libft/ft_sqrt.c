/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 23:23:05 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/09 02:47:21 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int n;

	n = nb / 2;
	if (nb <= 0)
		return (0);
	if (nb > 100000)
		n = n / 100;
	while (n > 0)
	{
		if ((n * n) == nb)
			return (n);
		n--;
	}
	return (0);
}
