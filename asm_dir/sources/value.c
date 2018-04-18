/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:11:37 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 23:30:53 by mbenjell         ###   ########.fr       */
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
	if ((ret == ERROR) && (d->error = E_NUMBER))
		return (ERROR);
	if (d->value[i] < 1 || d->value[i] > 16)
	{
		d->error = E_BAD_REG;
		return (ERROR);
	}
	speed_space(&arg);
	if (*arg && (d->error = E_ARG))
		return (ERROR);
	return (SUCCESS);
}

static int	extract_dir(t_data *d, int i)
{
	int		ret;
	char	*arg;

	arg = d->arg[i];
	arg++;
	if (*arg == LABEL_CHAR)
	{
		d->type[i] |= T_LAB;
		return (SUCCESS);
	}
	ret = ft_watoi(&arg, &d->value[i]);
	if ((ret == ERROR) && (d->error = E_NUMBER))
		return (ERROR);
	speed_space(&arg);
	if (*arg && (d->error = E_ARG))
		return (ERROR);
	return (SUCCESS);
}

static int	extract_ind(t_data *d, int i)
{
	int		ret;
	char	*arg;

	arg = d->arg[i];
	if (*arg == LABEL_CHAR)
	{
		d->type[i] |= T_LAB;
		return (SUCCESS);
	}
	ret = ft_watoi(&arg, &d->value[i]);
	if ((ret == ERROR) && (d->error = E_NUMBER))
		return (ERROR);
	speed_space(&arg);
	if (*arg && (d->error = E_ARG))
		return (ERROR);
	return (SUCCESS);
}

int			extract_values(t_data *d)
{
	int		i;
	int		ret;
	char	**arg;

	i = 0;
	ret = 0;
	arg = d->arg;
	while (arg[i])
	{
		if (d->type[i] == T_REG)
			ret = extract_reg(d, i);
		if (d->type[i] == T_DIR)
			ret = extract_dir(d, i);
		if (d->type[i] == T_IND)
			ret = extract_ind(d, i);
		if (ret == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
