/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_power_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:24:03 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/26 16:55:07 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_a_power_b(int a, unsigned int b)
{
	unsigned int	i;
	int				result;

	result = 1;
	i = 0;
	while (i < b)
	{
		result *= a;
		i++;
	}
	return (result);
}
