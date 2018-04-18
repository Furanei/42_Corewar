/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:20:34 by mbriffau          #+#    #+#             */
/*   Updated: 2018/04/12 22:26:37 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	choice_type(int idx_type, int type, int cmp)
{
	int		dst;

	dst = 0;
	if (idx_type == 0)
	{
		dst = ((type & T_REG) ? T_REG_1 : dst);
		dst = ((type & T_DIR) ? T_DIR_1 : dst);
		dst = ((type & T_IND) ? T_IND_1 : dst);
	}
	else if (idx_type == 1)
	{
		dst = ((type & T_REG) ? T_REG_2 : dst);
		dst = ((type & T_DIR) ? T_DIR_2 : dst);
		dst = ((type & T_IND) ? T_IND_2 : dst);
	}
	else if (idx_type == 2)
	{
		dst = ((type & T_REG) ? T_REG_3 : dst);
		dst = ((type & T_DIR) ? T_DIR_3 : dst);
	}
	return (dst & cmp);
}

int			checker(t_instr *instr)
{
	int		cmp;

	cmp = 0xFFFFFFFF;
	instr->nb_arg = 0;
	if (!instr->type[0])
		return (0);
	while ((instr->nb_arg < 3) && (instr->type[instr->nb_arg] != 0))
	{
		cmp = choice_type(instr->nb_arg, instr->type[instr->nb_arg], cmp);
		instr->nb_arg++;
	}
	cmp = ((instr->nb_arg == 1) ? cmp & T1 : cmp);
	cmp = ((instr->nb_arg == 2) ? cmp & T2 : cmp);
	cmp = ((instr->nb_arg == 3) ? cmp & T3 : cmp);
	cmp = (cmp & (1 << (instr->opcode - 1)));
	return (cmp);
}
