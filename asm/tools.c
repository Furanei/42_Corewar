/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:15:04 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/02 04:09:21 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	long	nb;

	nb = 0;
	while (is_space(nptr))
		;
	if (!(**nptr && **nptr >= '0' && **nptr <= '9'))
		return (ERROR);
	while (**nptr && **nptr >= '0' && **nptr <= '9')
	{
		nb = nb * 10 + **nptr - '0';
		if (nb < INT_MIN || nb > INT_MAX)
			return (ERROR);
		(*nptr)++;
	}
	*res = nb;
	return (0);
}

int			ft_catoi(char *nptr, int *res)
{
	long	nb;

	nb = 0;
	while (*nptr++ == ' ')
		;
	nptr--;
	if (!(*nptr && *nptr >= '0' && *nptr <= '9'))
		return (ERROR);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - '0';
		if (nb < INT_MIN || nb > INT_MAX)
			return (ERROR);
		nptr++;
	}
	*res = nb;
	return (0);
}
