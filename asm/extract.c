/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:15:53 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 22:42:54 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			extract_header(t_data *d)
{
	char	*line;

	line = d->buff;
	if (ft_strequ(NAME_CMD_STRING, line))
		line += ft_strlen(NAME_CMD_STRING);
	else if (ft_strequ(COMMENT_CMD_STRING, line))
		line += ft_strlen(COMMENT_CMD_STRING);
	else
		return (ERROR);
	d->line = line;
	return (0);
}

static int	is_successive(char *s, char c)
{
	while (*(s + 1))
	{
		if ((s[0] == c) && (s[1] == c))
			return (1);
		s++;
	}
	return (0);
}

static int	split_arg(t_data *d)
{
	char	*line;
	int		count;

	d->line_arg = (char*)ft_memalloc(sizeof(char) * (ft_strlen(d->line) + 1));
	if (d->line_arg == NULL)
		return (ERROR);
	ft_strdcpy(d->line_arg, d->line, " \t");
	count = 0;
	line = d->line_arg;
	while (*line)
	{
		if (*line == SEPARATOR_CHAR)
			count++;
		if (count > 2)
			return (ERROR);
		line++;
	}
	if (!ft_strlen(d->line_arg) || is_successive(d->line_arg, SEPARATOR_CHAR))
		return (ERROR);
	d->arg = ft_strsplit(d->line_arg, SEPARATOR_CHAR);
	if (d->arg == NULL)
		return (ERROR);
	return (SUCCESS);
}

static int	parse_instr(t_data *d)
{
	if (split_arg(d) == ERROR)
		return (ERROR);
	if (extract_types(d) == ERROR)
		return (ERROR);
	if (extract_values(d) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			extract_instr(t_data *d)
{
	int		i;
	char	*line;
	char	*name;

	i = 0;
	line = d->line;
	while (is_space(&line))
		;
	while (i < 16)
	{
		name = g_op_tab[i].name;
		if (ft_strnequ(name, line, ft_strlen(name)))
		{
			line += ft_strlen(name);
			if ((*line != DIRECT_CHAR) && !is_space(&line))
				return (ERROR);
			d->line = line;
			d->opcode = i + 1;
			if (parse_instr(d) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ERROR);
}
