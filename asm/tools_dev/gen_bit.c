/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:13:48 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/17 02:01:37 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		gen_bit(char *s)
{
	int i = 0;
	int ret;
	int dest = 0;

	while (s[i]  && (ret = atoi(&s[i])))
	{
		dest += (1 << (ret - 1));
		while (s[i] && s[++i] != ' ')
			;
	}
	return (dest);
}

int 	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", gen_bit(av[1]));
	}

	return (0);
}