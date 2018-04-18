/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:15:53 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 04:48:33 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	if (d->line_arg == NULL && (d->error = MALLOC_FAILED))
		return (ERROR);
	ft_strdcpy(d->line_arg, d->line, " \t");
	count = 0;
	line = d->line_arg;
	while (*line)
	{
		if (*line == SEPARATOR_CHAR)
			count++;
		if (count > 2 && (d->error = E_VIRGULE))
			return (ERROR);
		line++;
	}
	if (!ft_strlen(d->line_arg) || is_successive(d->line_arg, SEPARATOR_CHAR))
		return (ERROR);
	d->arg = ft_strsplit(d->line_arg, SEPARATOR_CHAR);
	ft_strdel(&d->line_arg);
	if (d->arg == NULL && (d->error = MALLOC_FAILED))
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

static int	check_arg(t_data *d, char **line)
{
	if ((**line != DIRECT_CHAR) && !is_space(line))
	{
		d->error = E_NO_ARG;
		return (ERROR);
	}
	return (SUCCESS);
}

int			extract_instr(t_data *d)
{
	int		i;
	char	*line;
	char	*name;

	i = -1;
	line = d->line;
	speed_space(&line);
	while (++i < 16)
	{
		name = g_op_tab[i].name;
		if (ft_strnequ(name, line, ft_strlen(name)))
		{
			if (*(line + ft_strlen(name)) == 'i')
				continue ;
			line += ft_strlen(name);
			if (check_arg(d, &line) == ERROR)
				return (ERROR);
			d->line = line;
			d->opcode = i + 1;
			if (parse_instr(d) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
	}
	return (ERROR);
}
