/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:33:10 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/17 04:49:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned long ten;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		n = -n;
		ft_putchar('-');
	}
	ten = 10;
	while (n / ten)
		ten = ten * 10;
	ten /= 10;
	while (ten >= 10)
	{
		ft_putchar((n / ten) + 48);
		n = n % ten;
		ten = ten / 10;
	}
	ft_putchar((n % 10) + 48);
}
