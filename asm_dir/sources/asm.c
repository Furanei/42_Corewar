/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:47:22 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 23:11:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_close(int *fd)
{
	if (*fd)
	{
		close(*fd);
		*fd = 0;
	}
}

int				main(int ac, char **av)
{
	t_data		d;
	int			ret;

	ft_bzero(&d, sizeof(t_data));
	if (ac != 2)
		return (ft_usage());
	d.file_s = av[1];
	ret = file_name(&d);
	if (ret == ERROR)
		return (ft_error(&d));
	d.fd = open(av[1], O_RDONLY);
	if (d.fd == -1 && (d.error = E_OPEN_FILE))
		return (ft_error(&d));
	d.state = P_HEADER;
	ret = parser(&d);
	if (ret == ERROR)
		return (ft_error(&d));
	reverse_instr(&d);
	reverse_label(&d);
	ret = replace_labels(&d);
	if (ret == ERROR)
		return (ft_error(&d));
	writer(&d);
	free_data(&d);
	return (SUCCESS);
}
