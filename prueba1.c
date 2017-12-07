/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:24:12 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/06 22:40:27 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
int		main()
{
/*		char *line;
		int out;
		int p[2];
		char *str;
		int len = 50;

		str = (char *)malloc(1000 * 1000);
		*str = '\0';
		while (len--)
			strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
		out = dup(1);
		pipe(p);
		dup2(p[1], 1);

		if (str)
			write(1, str, strlen(str));
		close(p[1]);
		dup2(out, 1);
		get_next_line(p[0], &line);
	
		if(!strcmp(line, str))
	ft_putstr("\ncosabona\n");*/
	int fd;
	char *str;

	fd = open("gnl3_3.txt", O_RDONLY);
	while (get_next_line(fd,&str))
	{
		ft_putchar('<');
		if (*str < 31)
			ft_putnbr(*str);
		else
			ft_putstr(str);
		ft_putchar('>');
		ft_putchar('\n');
	}






	return (0);
}
