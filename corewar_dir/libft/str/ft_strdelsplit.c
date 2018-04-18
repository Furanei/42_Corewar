/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:01:10 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/16 23:38:07 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdelsplit(char ***as)
{
	unsigned int	i;

	if (*as != NULL)
	{
		i = 0;
		while ((*as)[i] != NULL)
		{
			ft_strdel(&((*as)[i]));
			i++;
		}
	}
	ft_memdel((void **)(*as));
}
