/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:11:37 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 00:18:03 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	extract_reg(t_data *d, int i)
{
	int		ret;
	char	*arg;

	arg = d->arg[i];
	arg++;
	ret = ft_watoi(&arg, &d->value[i]);
	if (ret == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	extract_dir(t_data *d, int i)
{
	int		ret;
	char	*arg;

	arg = d->arg[i];
	arg++;
	ret = ft_watoi(&arg, &d->value[i]);
	if (ret == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	extract_ind(t_data *d, int i)
{
	int		ret;
	char	*arg;

	arg = d->arg[i];
	ret = ft_watoi(&arg, &d->value[i]);
	if (ret == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			extract_values(t_data *d)
{
	int		i;
	char	**arg;

	i = 0;
	arg = d->arg;
	while (arg[i])
	{
		d->type[i] == T_REG ? extract_reg(d, i) : 42;
		d->type[i] == T_DIR ? extract_dir(d, i) : 42;
		d->type[i] == T_IND ? extract_ind(d, i) : 42;
		i++;
	}
	return (SUCCESS);
}
