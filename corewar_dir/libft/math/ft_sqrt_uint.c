/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:10:05 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:29:47 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sqrt_uint(unsigned int ui)
{
	unsigned int	inf;
	unsigned int	sup;
	unsigned int	temp;

	if ((ui == 0) || (ui == 1))
		return (ui);
	sup = 1;
	while ((sup < 65535) && (sup * sup) < ui)
		sup *= 2;
	inf = sup / 2;
	while ((inf < sup) && ((inf + 1) != sup))
	{
		temp = (inf / 2) + (sup / 2);
		if ((temp * temp) < ui)
			inf = temp;
		else
			sup = temp;
	}
	return (sup);
}
/*
**  #include <stdio.h>
**  #include <unistd.h>
**
**  int		main(void)
**  {
**  	unsigned int	ui;
**
**  	ui = 4294967296 - 5;
**  	while (ui != (unsigned int)(5))
**  	{
**  		printf(" i  = %u""\n", ui);
**  		printf(" V  = %u""\n", ft_sqrt_uint(ui));
**  		printf("V*V = %u""\n\n", ft_sqrt_uint(ui) * ft_sqrt_uint(ui));
**  		ui++;
**  		sleep(1);
**  	}
**  	printf(" l  = %u""\n", ui);
**  	return (0);
**  }
*/
