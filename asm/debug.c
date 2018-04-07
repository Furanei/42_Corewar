/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:13:06 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 20:48:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	print_arg(char **arg, int *value)
{
	while (*arg)
	{
		ft_printf("%s = %d | ", *arg, *value);
		arg++;
		value++;
	}
}

void		display_instr(t_data *d)
{
	t_instr *i;

	i = d->instr;
	while (i)
	{
		ft_printf("CODE = %d | ARGS = { ", i->opcode);
		print_arg(i->arg, i->value);
		ft_printf(" }\n");
		i = i->next;
	}
}

void		display_label(t_data *d)
{
	t_label	*l;
	size_t	i;

	l = d->label;
	i = 0;
	while (l)
	{
		ft_printf("label[%d] == '%s' (opcode == %d)\n", i++, l->name,
			l->instr->opcode);
		l = l->next;
	}
}
