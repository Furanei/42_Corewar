/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:24:52 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 23:10:11 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_arg(t_instr *i)
{
	char		**tmp;

	tmp = i->arg;
	while (*tmp)
		ft_strdel(tmp++);
	free(i->arg);
	i->arg = NULL;
}

static void		free_label(t_data *d)
{
	t_label		*l;
	t_label		*tmp;

	l = d->label;
	while (l)
	{
		ft_strdel(&l->name);
		tmp = l;
		l = l->next;
		ft_memdel((void**)&tmp);
	}
}

static void		free_instr(t_data *d)
{
	t_instr		*i;
	t_instr		*tmp;

	i = d->instr;
	while (i)
	{
		free_arg(i);
		tmp = i;
		i = i->next;
		ft_memdel((void**)&tmp);
	}
}

void			free_data(t_data *d)
{
	char		**tmp;

	ft_strdel(&d->file_cor);
	ft_strdel(&d->buff);
	ft_strdel(&d->line_arg);
	free_instr(d);
	free_label(d);
	if (d->arg != NULL)
	{
		tmp = d->arg;
		while (*tmp)
			ft_strdel(tmp++);
		free(d->arg);
		d->arg = NULL;
	}
	ft_close(&d->fd);
}
