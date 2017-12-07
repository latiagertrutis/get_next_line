/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:08:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/11/17 04:52:07 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long ten;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		n = -n;
		ft_putchar_fd('-', fd);
	}
	ten = 10;
	while (n / ten)
		ten = ten * 10;
	ten /= 10;
	while (ten >= 10)
	{
		ft_putchar_fd((n / ten) + 48, fd);
		n = n % ten;
		ten = ten / 10;
	}
	ft_putchar_fd((n % 10) + 48, fd);
}
