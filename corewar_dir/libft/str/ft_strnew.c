/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:37:00 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:41:15 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	result = (char *)ft_memalloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
