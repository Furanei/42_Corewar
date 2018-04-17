/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 04:35:09 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 00:19:24 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	extract_name(t_data *d)
{
	char	*line;
	char	*end;
	char	*temp;

	line = d->line;
	speed_space(&line);
	if (*line != QUOTE_CHAR && (d->error = E_QUOTE))
		return (ERROR);
	line++;
	end = ft_strchr(line, QUOTE_CHAR);
	if (end == NULL && (d->error = E_QUOTE))
		return (ERROR);
	temp = end + 1;
	speed_space(&temp);
	if (*temp != 0 && (d->error = E_BAD_HEADER))
		return (ERROR);
	*end = 0;
	if (ft_strlen(line) > PROG_NAME_LENGTH && (d->error = E_LONG_NAME))
		return (ERROR);
	ft_strncpy(d->prog_name, line, PROG_NAME_LENGTH);
	d->get_name = 1;
	d->line = line;
	return (SUCCESS);
}

static int	extract_comment(t_data *d)
{
	char	*line;
	char	*end;
	char	*temp;

	line = d->line;
	speed_space(&line);
	if (*line != QUOTE_CHAR && (d->error = E_QUOTE))
		return (ERROR);
	line++;
	end = ft_strchr(line, QUOTE_CHAR);
	if (end == NULL && (d->error = E_QUOTE))
		return (ERROR);
	temp = end + 1;
	speed_space(&temp);
	if (*temp != 0 && (d->error = E_BAD_HEADER))
		return (ERROR);
	*end = 0;
	if (ft_strlen(line) > COMMENT_LENGTH && (d->error = E_LONG_COMM))
		return (ERROR);
	ft_strncpy(d->comment, line, COMMENT_LENGTH);
	d->get_comment = 1;
	d->line = line;
	return (SUCCESS);
}

int			extract_header(t_data *d)
{
	char	*line;
	int		ret;

	ret = SUCCESS;
	line = d->line;
	if (ft_strnequ(NAME_STRING, line, ft_strlen(NAME_STRING)))
	{
		line += ft_strlen(NAME_STRING);
		d->line = line;
		ret = extract_name(d);
	}
	else if (ft_strnequ(COMMENT_STRING, line, ft_strlen(COMMENT_STRING)))
	{
		line += ft_strlen(COMMENT_STRING);
		d->line = line;
		ret = extract_comment(d);
	}
	else if ((d->error = E_BAD_HEADER))
		return (ERROR);
	d->line = line;
	return (ret);
}
