/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 22:49:53 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/02 05:20:57 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_line(char *buff, size_t size)
{
	size_t i;

	i = 0;
	while (buff[i] && buff[i] != END_OF_LINE && i < size)
		i++;
	if (i == size)
		return (-1);
	return (i);
}

static t_list	*update_list(t_list **head, int fd)
{
	t_list *aux;

	if (!(*head))
	{
		if (!(*head = (t_list *)ft_memalloc(sizeof(t_list))))
			return (NULL);
		(*head)->content = NULL;
		(*head)->content_size = fd;
		(*head)->next = NULL;
	}
	else
	{
		if (!(aux = (t_list *)ft_memalloc(sizeof(t_list))))
			return (NULL);
		(aux)->content = NULL;
		(aux)->content_size = fd;
		(aux)->next = NULL;
		ft_lstadd(head, aux);
	}
	return (*head);
}

static char		*ini_line(t_list *lines)
{
	char *line;

	if (lines->content)
	{
		line = ft_strdup(lines->content);
		ft_memdel(&(lines->content));
	}
	else
		line = ft_strnew(0);
	return (line);
}

static int		read_line(t_list *lines, int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		rd;
	char	*aux;
	int		pos;

	*line = ini_line(lines);
	while (1)
	{
		ft_memset(buff, 0, BUFF_SIZE + 1);
		if ((rd = read(fd, buff, BUFF_SIZE)) <= 0)
			return ((!rd && **line) ? 1 : rd);
		if ((pos = check_line(buff, BUFF_SIZE)) >= 0)
		{
			aux = ft_strnjoin(*line, buff, pos);
			ft_strdel(line);
			*line = aux;
			if (buff[pos + 1])
				lines->content = ft_strsub(buff, pos + 1, rd - pos - 1);
			return ((*line) ? 1 : -1);
		}
		aux = ft_strjoin(*line, buff);
		ft_strdel(line);
		*line = aux;
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*aux_lst;
	int				pos;
	char			*aux_str;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	aux_lst = ft_lst_search_by_size(head, fd);
	if (!head || !aux_lst)
		if (!(aux_lst = update_list(&head, fd)))
			return (-1);
	if (!aux_lst->content)
		return (read_line(aux_lst, fd, line));
	aux_str = (char *)aux_lst->content;
	if ((pos = check_line(aux_str, ft_strlen(aux_str))) < 0)
		return (read_line(aux_lst, fd, line));
	*line = ft_strncpy(ft_strnew(pos + 1), aux_str, pos);
	aux_str = ft_strsub(aux_str, pos + 1, ft_strlen(aux_str) - pos - 1);
	ft_memdel(&(aux_lst->content));
	aux_lst->content = aux_str;
	return ((*line) ? 1 : -1);
}
