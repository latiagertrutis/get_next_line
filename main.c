/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:35:26 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/02 05:32:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	char *line;
	int ret;

/*		char 	*line;
		int		out;
		int		p[2];
		int		fd;
		int		ret;

		out = dup(1);
		pipe(p);

		fd = 1;
		dup2(p[1], fd);
		write(fd, "abcdefghijklmnop\n", 17);
		write(fd, "qrstuvwxyzabcdef\n", 17);
		close(p[1]);
		dup2(out, fd);
		get_next_line(p[0], &line);
		printf("Linea1: %s\n", line);
		get_next_line(p[0], &line);
		printf("Linea2: %s\n", line);
		ret = get_next_line(p[0], &line);
		printf("Linea3: %d\n", ret);
	
*/	

	(void)ac;
	if ((fd  = open(av[1], O_RDONLY)) < 0)
	{
		printf("ERROR AL ABRIR");
		return (0);
	}
	else
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ft_putstr("<");
			ft_putstr(line);
			ft_putstr(">");
			ft_putstr("\n");
			ft_strdel(&line);
		}
	}
	ft_strdel(&line);
	return (0);
}
