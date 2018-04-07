/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:56:36 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/02 04:09:17 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	detect_type(int *type, char *arg)
{
	if (*arg == DIRECT_CHAR)
		*type = T_DIR;
	else if (*arg == 'r')
		*type = T_REG;
	else
		*type = T_IND;
	return (SUCCESS);
}

int			extract_types(t_data *d)
{
	int		i;
	int		ret;
	char	**arg;
	int		*type;

	i = 0;
	arg = d->arg;
	type = d->type;
	while (arg[i] && (i < 3))
	{
		ret = detect_type(&type[i], arg[i]);
		if (ret == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
