/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:29:01 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 20:45:23 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	add_label(t_data *d)
{
	t_label	*l;

	l = (t_label*)ft_memalloc(sizeof(t_label));
	if (l == NULL)
		return (ERROR);
	l->name = d->label_name;
	l->next = d->label;
	d->label = l;
	return (SUCCESS);
}

static int	valid_label(char *name)
{
	while (*name)
		if (!ft_strchr(LABEL_CHARS, *name++))
			return (ERROR);
	return (SUCCESS);
}

int			extract_label(t_data *d)
{
	char	*delim;

	while (is_space(&d->line))
		;
	delim = ft_strchr(d->line, LABEL_CHAR);
	if (delim == NULL)
		return (SUCCESS);
	d->label_name = ft_strsub(d->line, 0, (unsigned int)(delim - d->line));
	if (d->label_name == NULL)
		return (ERROR);
	if (valid_label(d->label_name) == ERROR)
		return (ERROR);
	if (add_label(d) == ERROR)
		return (ERROR);
	d->line = ++delim;
	d->active_lab = 1;
	return (SUCCESS);
}
