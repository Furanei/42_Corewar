/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:56:36 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/10 05:37:01 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	detect_type(int *type, char *arg)
{
	if (ft_strnequ(arg, "%:", 2))
		*type = T_DIR | T_LAB;
	else if (*arg == DIRECT_CHAR)
		*type = T_DIR;
	else if (*arg == 'r')
		*type = T_REG;
	else if (*arg == LABEL_CHAR)
		*type = T_IND | T_LAB;
	else
		*type = T_IND;
}

int			extract_types(t_data *d)
{
	int		i;
	char	**arg;
	int		*type;

	i = 0;
	arg = d->arg;
	type = d->type;
	while (arg[i] && (i < 3))
	{
		detect_type(&type[i], arg[i]);
		i++;
	}
	return (SUCCESS);
}
