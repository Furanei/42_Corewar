/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:25:39 by mbenjell          #+#    #+#             */
/*   Updated: 2018/02/10 03:01:06 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			new_file(int fd, int *start, t_gnl *s)
{
	*start = 1;
	s->fd = fd;
	s->buff_init = malloc(0);
	s->buff = NULL;
	s->p = NULL;
	s->nb = 0;
	s->j = 0;
	s->fin = 1;
	s->mem = NULL;
	return (0);
}

static int			write_line(t_gnl *s, char **line)
{
	t_mem			*mem;
	t_mem			*temp;
	char			*line_start;

	if (!(*line = ft_memalloc(sizeof(char) * (s->j + 1))))
		return (-1);
	mem = s->mem;
	line_start = *line;
	line_start += s->j;
	while (mem)
	{
		line_start -= mem->nb;
		ft_memcpy(line_start, mem->m, mem->nb);
		temp = mem;
		mem = mem->next;
		free(temp->m);
		temp->m = NULL;
		free(temp);
		temp = NULL;
	}
	s->j = 0;
	s->mem = NULL;
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*s;
	static int		start = 0;
	static int		end = 0;
	static int		old_fd = -1;

	if (line == NULL || fd < 0)
		return (-1);
	if ((old_fd != fd) || !start)
	{
		if (!(s = (t_gnl*)malloc(sizeof(t_gnl))))
			return (-1);
		start = 0;
		end = 0;
		old_fd = fd;
	}
	if (end)
		return (0);
	if (!start)
		new_file(fd, &start, s);
	if (((s->i = get_line(s)) != -1) && (write_line(s, line) == -1))
		return (-1);
	if ((s->i == 0) && ft_strlen(*line) == 0)
		return (new_file(fd, &start, s));
	s->mem = NULL;
	return (s->i ? s->i : (end = 1));
}
