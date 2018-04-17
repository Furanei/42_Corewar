/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:26:05 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:39:28 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	if ((s != NULL) && (f != NULL))
	{
		result = (char *)ft_memalloc((ft_strlen((char *)s) + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			result[i] = f(s[i]);
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
