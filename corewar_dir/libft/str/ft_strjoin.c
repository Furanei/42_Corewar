/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:51:26 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:38:45 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	size_result;

	if ((s1 != NULL) && (s2 != NULL))
	{
		size_result = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		result = (char *)ft_memalloc((size_result + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
		i = 0;
		ft_strcpy(result, (char *)s1);
		ft_strcat(result, s2);
		return (result);
	}
	else
		return (NULL);
}
