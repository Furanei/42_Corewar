/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:05:42 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 22:37:48 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				add_instr(t_data *d)
{
	t_instr		*instr;

	instr = (t_instr*)ft_memalloc(sizeof(t_instr));
	if (instr == NULL)
		return (ERROR);
	instr->opcode = d->opcode;
	instr->arg = d->arg;
	ft_memcpy(instr->type, d->type, sizeof(int) * 3);
	ft_memcpy(instr->value, d->value, sizeof(int) * 3);
	ft_bzero(d->type, sizeof(int) * 3);
	ft_bzero(d->value, sizeof(int) * 3);
	instr->next = d->instr;
	d->instr = instr;
	if (d->label && d->active_lab)
	{
		d->label->instr = instr;
		d->active_lab = 0;
	}
	if (checker(instr) == 0)
	{
		ft_printf("ERROR TYPAGE ! here : %s\n", d->buff);
		ft_printf("%d - %d - %d\n", instr->type[0], instr->type[1], instr->type[2]);
		return (ERROR);
	}
	return (SUCCESS);
}
