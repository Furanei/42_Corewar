/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:33:48 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:41:49 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	*temp;

	if ((char)c == '\0')
		return (ft_strchr(s, c));
	result = NULL;
	temp = ft_strchr(s, c);
	while (temp != NULL)
	{
		result = temp;
		temp = ft_strchr(result + 1, c);
	}
	return (result);
}
