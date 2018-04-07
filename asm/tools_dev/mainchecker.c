/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 13:07:23 by mbriffau          #+#    #+#             */
/*   Updated: 2018/04/05 22:20:53 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"
#include "../op.h"
#include <strings.h>
#include <stdio.h>

int		checker(t_instr *instr);

int main(int ac, char **av)
{
	t_instr		instr;
	int ret  = 0;

	bzero(&instr, sizeof(t_instr));

	instr.opcode = 1;
	instr.type[0]= T_DIR;
	instr.type[1]= 0;
	instr.type[2]= 0;
	ret = checker(&instr);

	printf("%d\n", ret);
	return (0);
}
