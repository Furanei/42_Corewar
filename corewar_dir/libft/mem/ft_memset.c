/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:52:19 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:32:49 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i_len;
	unsigned char	*result;

	result = (unsigned char *)b;
	i_len = 0;
	while (i_len < len)
	{
		result[i_len] = (unsigned char)c;
		i_len++;
	}
	return (b);
}
