/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:05:42 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/16 23:04:41 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		labels_no_instr(t_data *d, t_instr *i)
{
	t_label		*l;

	l = d->label;
	while (l && (l->instr == NULL))
	{
		l->instr = i;
		l = l->next;
	}
	d->active_lab = 0;
}

int				add_instr(t_data *d)
{
	t_instr		*instr;

	instr = (t_instr*)ft_memalloc(sizeof(t_instr));
	if (instr == NULL && (d->error = MALLOC_FAILED))
		return (ERROR);
	instr->opcode = d->opcode;
	instr->arg = d->arg;
	d->arg = NULL;
	ft_memcpy(instr->type, d->type, sizeof(int) * 3);
	ft_memcpy(instr->value, d->value, sizeof(int) * 3);
	ft_bzero(d->type, sizeof(int) * 3);
	ft_bzero(d->value, sizeof(int) * 3);
	instr->next = d->instr;
	d->instr = instr;
	if (d->label && d->active_lab)
		labels_no_instr(d, instr);
	if (checker(instr) == 0 && (d->error = E_TYPE))
		return (ERROR);
	instr->pc = d->pc;
	lg_instr(instr);
	d->pc += instr->lg;
	instr->line = d->nb_line;
	return (SUCCESS);
}

void			reverse_instr(t_data *d)
{
	t_instr		*i;
	t_instr		*temp;
	t_instr		*order;

	i = d->instr;
	order = NULL;
	while (i)
	{
		temp = i;
		i = i->next;
		temp->next = order;
		order = temp;
	}
	d->instr = order;
}
