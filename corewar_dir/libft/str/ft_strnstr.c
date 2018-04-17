/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:04:37 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:41:36 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	int i_b;
	int i_l;

	if (little[0] == '\0')
	{
		return (big);
	}
	i_b = 0;
	i_l = 0;
	while ((big[i_b] != '\0') && (little[i_l] != '\0') && (i_b < (int)len))
	{
		i_l = 0;
		while ((little[i_l] == big[i_b + i_l])
				&& (little[i_l] != '\0')
				&& (i_b + i_l < (int)len))
			i_l++;
		i_b++;
	}
	if (little[i_l] == '\0')
		return (&big[i_b - 1]);
	return (NULL);
}
