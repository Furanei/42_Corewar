/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 11:41:37 by enanrock          #+#    #+#             */
/*   Updated: 2017/09/21 13:10:41 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoui(const char *str)
{
	int				signe;
	unsigned int	result;
	unsigned int	i;

	result = 0;
	i = 0;
	while ((str[i] == 9) || (str[i] == 10) || (str[i] == 11)
			|| (str[i] == 12) || (str[i] == 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else
	{
		signe = 1;
		if (str[i] == '+')
			i++;
	}
	while (('0' <= str[i]) && (str[i] <= '9'))
		result = (10 * result) + str[i++] - '0';
	return (signe * result);
}
