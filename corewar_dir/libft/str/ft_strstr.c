/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:25:35 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:42:33 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i_s;
	int i_f;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	i_s = 0;
	i_f = 0;
	while ((str[i_s] != '\0') && (to_find[i_f] != '\0'))
	{
		i_f = 0;
		while ((to_find[i_f] == str[i_s + i_f]) && (to_find[i_f] != '\0'))
		{
			i_f++;
		}
		i_s++;
	}
	if (to_find[i_f] == '\0')
	{
		return (&str[i_s - 1]);
	}
	return (NULL);
}
