/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:15:38 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/12 20:25:03 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			calcul_ocp(t_instr *i)
{
	int		n;
	char	ocp;
	int		decal;

	n = 0;
	ocp = 0;
	decal = 3;
	while (n < i->nb_arg)
	{
		if (i->type[n] & T_REG)
			ocp |= 0b01 << (decal * 2);
		else if (i->type[n] & T_DIR)
			ocp |= 0b10 << (decal * 2);
		else if (i->type[n] & T_IND)
			ocp |= 0b11 << (decal * 2);
		decal--;
		n++;
	}
	i->ocp = ocp;
	return (SUCCESS);
}

static void	calcul_address(int *v, unsigned int start, unsigned int end)
{
	if (start < end)
		*v = 0xffff - (end - start) + 1;
	else
		*v = start - end;
}

int			calcul_label(t_data *d, t_instr *i, int n)
{
	t_label	*lst;
	char	*arg;

	lst = d->label;
	arg = i->arg[n];
	if (i->type[n] & T_DIR)
		arg += 2;
	else
		arg++;
	while (lst)
	{
		if (ft_strequ(lst->name, arg))
		{
			if (lst->instr == NULL)
				calcul_address(&i->value[n], d->pc, i->pc);
			else
				calcul_address(&i->value[n], lst->instr->pc, i->pc);
			return (SUCCESS);
		}
		lst = lst->next;
	}
	d->nb_line = i->line;
	d->error = E_LABEL_NOT_FOUND;
	return (ERROR);
}

void		lg_instr(t_instr *i)
{
	int		n;
	int		size;
	int		dir_size;

	n = 0;
	size = 1;
	dir_size = 2;
	if (g_op_tab[i->opcode - 1].boolean_length_direct == 0)
		dir_size = 4;
	if (g_op_tab[i->opcode - 1].boolean_argument_coding_byte == 1)
		size++;
	while (n < i->nb_arg)
	{
		if (i->type[n] & T_REG)
			size += 1;
		if (i->type[n] & T_DIR)
			size += dir_size;
		if (i->type[n] & T_IND)
			size += 2;
		n++;
	}
	i->lg = size;
}

void		lg_champion(t_data *d)
{
	t_instr	*i;

	i = d->instr;
	while (i)
	{
		lg_instr(i);
		d->lg_champion += i->lg;
		i = i->next;
	}
}
