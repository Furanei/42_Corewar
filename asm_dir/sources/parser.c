/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:05:52 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/16 21:35:42 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	extract_data(t_data *d)
{
	if (d->state == P_HEADER)
		return (extract_header(d));
	else if (d->state == P_INSTR)
	{
		if (~extract_label(d))
		{
			if (ft_strlen(d->line) == 0)
				return (SUCCESS);
			if (~extract_instr(d) && ~extract_types(d))
				return (add_instr(d));
		}
		else
		{
			ft_strdel(&d->label_name);
			if (~extract_instr(d) && ~extract_types(d))
				return (add_instr(d));
		}
	}
	return (ERROR);
}

static int	extract_info(t_data *d)
{
	int		ret;
	char	*comm;

	ret = 0;
	if (!ft_strncmp("#", d->line, 1))
		return (SUCCESS);
	else
	{
		comm = ft_strchr(d->line, COMMENT_CHAR);
		if (comm)
			*comm = 0;
		if (d->get_name && d->get_comment)
			d->state = P_INSTR;
		ret = extract_data(d);
	}
	return (ret);
}

int			parser(t_data *d)
{
	int		ret;

	while ((ret = get_next_line(d->fd, &d->buff)))
	{
		if (ret == ERROR && (d->error = MALLOC_FAILED))
			return (ERROR);
		d->line = d->buff;
		speed_space(&d->line);
		if (ft_strlen(d->line) == 0)
		{
			ft_strdel(&d->buff);
			d->nb_line++;
			continue ;
		}
		if (extract_info(d) == ERROR)
			return (ERROR);
		d->nb_line++;
		ft_strdel(&d->buff);
	}
	ft_strdel(&d->buff);
	if ((!d->get_name || !d->get_comment) && (d->error = E_INC_HEADER))
		return (ERROR);
	return (SUCCESS);
}
