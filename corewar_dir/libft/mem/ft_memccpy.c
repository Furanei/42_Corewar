/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:41:50 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:30:57 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	while ((i < n) && (temp_src[i] != (unsigned char)c))
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	if (n == i)
		return (NULL);
	else if ((n < i) && (temp_dst[i] == (unsigned char)c))
		return (NULL);
	else
	{
		temp_dst[i] = temp_src[i];
		return (temp_dst + i + 1);
	}
}
