/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:43:45 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/17 04:32:14 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "and.h"

void	and(void *p1, void *p2, unsigned int arg[MAX_ARGS_NUMBER][5])
{
	t_local_memory	*read_head;
	t_mem			*mem;
	unsigned int	result;
	unsigned int	i;

	read_head = p1;
	mem = p2;
	result = arg[0][1] & arg[1][1];
	i = 0;
	while (i < REG_SIZE)
	{
		read_head->registers[arg[2][0]][i] =
			(result / ft_a_power_b(0x100, REG_SIZE - 1 - i)) % 0x100;
		i++;
	}
	read_head->carry = convert_pc_to_uint(read_head->registers[arg[1][0]]);
}
