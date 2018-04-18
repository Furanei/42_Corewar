/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 11:41:37 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/02 20:27:42 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int signe;
	int result;
	int i;

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
/*
**  #include <stdio.h>
**  #include <stdlib.h>
**
**  int		main(void)
**  {
**  	printf("ft_max = >%d<\n", ft_atoi("2147483647"));
**  	printf("   max = >%d<\n", atoi("2147483647"));
**  	printf("ft_max+1 = >%d<\n", ft_atoi("2147483648"));
**  	printf("   max+1 = >%d<\n", atoi("2147483648"));
**  	printf("ft_min = >%d<\n", ft_atoi("-2147483648"));
**  	printf("   min = >%d<\n", atoi("-2147483648"));
**  	printf("ft_min-1 = >%d<\n", ft_atoi("-2147483649"));
**  	printf("   min-1 = >%d<\n", atoi("-2147483649"));
**  	return (0);
**  }
*/
