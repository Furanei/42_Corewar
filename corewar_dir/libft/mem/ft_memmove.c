/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:43:13 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:32:29 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*temp_src;
	size_t			i;

	if (dst < src)
		result = ft_memcpy(dst, src, n);
	else
	{
		result = (unsigned char *)dst;
		temp_src = (unsigned char *)src;
		if (n == 0)
			return (result);
		i = n - 1;
		while (i > 0)
		{
			result[i] = temp_src[i];
			i--;
		}
		result[0] = temp_src[0];
	}
	return (result);
}
