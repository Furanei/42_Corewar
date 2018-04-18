/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:15:04 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/12 21:37:55 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		speed_space(char **c)
{
	while (is_space(c))
		;
}

int			is_space(char **c)
{
	if (**c == ' ' || **c == '\t')
	{
		(*c)++;
		return (1);
	}
	return (0);
}

int			ft_watoi(char **nptr, int *res)
{
	int		negatif;

	negatif = 0;
	speed_space(nptr);
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			negatif = 1;
		(*nptr)++;
	}
	if (!(**nptr && **nptr >= '0' && **nptr <= '9'))
		return (ERROR);
	while (**nptr && **nptr >= '0' && **nptr <= '9')
	{
		if (negatif)
			*res = *res * 10 - **nptr + '0';
		else
			*res = *res * 10 + **nptr - '0';
		(*nptr)++;
	}
	return (SUCCESS);
}

int			ft_catoi(char *nptr, int *res)
{
	int		negatif;

	negatif = 0;
	speed_space(&nptr);
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negatif = 1;
		(*nptr)++;
	}
	if (!(*nptr && *nptr >= '0' && *nptr <= '9'))
		return (ERROR);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		if (negatif)
			*res = *res * 10 - *nptr + '0';
		else
			*res = *res * 10 + *nptr - '0';
		nptr++;
	}
	return (SUCCESS);
}
