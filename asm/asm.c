/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:47:22 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 05:46:34 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	t_data	d;
	int		ret;

	ft_bzero(&d, sizeof(t_data));
	if (ac != 2)
		return (ERROR);
	d.fd = open(av[1], O_RDONLY);
	if (d.fd == -1)
		return (ERROR);
	d.state = P_INSTR;
	ret = parser(&d);
	display_instr(&d);
	display_label(&d);
	return (0);
}
