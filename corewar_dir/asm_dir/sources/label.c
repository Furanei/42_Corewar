/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:29:01 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/13 03:02:27 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	add_label(t_data *d)
{
	t_label	*l;

	l = (t_label*)ft_memalloc(sizeof(t_label));
	if (l == NULL && (d->error = MALLOC_FAILED))
		return (ERROR);
	l->name = d->label_name;
	l->next = d->label;
	l->line = d->nb_line;
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

	speed_space(&d->line);
	delim = ft_strchr(d->line, LABEL_CHAR);
	if (delim == NULL)
		return (SUCCESS);
	d->label_name = ft_strsub(d->line, 0, (unsigned int)(delim - d->line));
	if (d->label_name == NULL && (d->error = MALLOC_FAILED))
		return (ERROR);
	if (valid_label(d->label_name) == ERROR && (d->error = E_LABEL))
		return (ERROR);
	if (add_label(d) == ERROR)
		return (ERROR);
	d->line = ++delim;
	d->active_lab = 1;
	speed_space(&d->line);
	return (SUCCESS);
}

int			replace_labels(t_data *d)
{
	t_instr *i;
	int		n;
	int		ret;

	i = d->instr;
	n = 0;
	ret = SUCCESS;
	while (i)
	{
		while (n < i->nb_arg)
		{
			if (i->type[n] & T_LAB)
				ret = calcul_label(d, i, n);
			if (ret == ERROR)
				return (ERROR);
			n++;
		}
		n = 0;
		i = i->next;
	}
	return (SUCCESS);
}

void		reverse_label(t_data *d)
{
	t_label	*l;
	t_label	*temp;
	t_label	*order;

	l = d->label;
	order = NULL;
	while (l)
	{
		temp = l;
		l = l->next;
		temp->next = order;
		order = temp;
	}
	d->label = order;
}
