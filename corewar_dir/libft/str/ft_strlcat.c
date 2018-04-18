/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:39:56 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:39:01 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;

	i_dst = 0;
	while ((i_dst < size) && (dst[i_dst] != '\0'))
		i_dst++;
	i_src = 0;
	while ((size > 0) && ((i_dst + i_src) < (size - 1)) && (src[i_src] != '\0'))
	{
		dst[i_dst + i_src] = src[i_src];
		i_src++;
	}
	if ((i_dst + i_src) < size)
		dst[i_dst + i_src] = '\0';
	return (i_dst + ft_strlen((char *)src));
}
/*
**  #include <string.h>
**  #include <stdio.h>
**
**  int		main(void)
**  {
**  	char	ft_dst[100] = "dest";
**  	char	ft_src[100] = "src";
**  	char	dst[100] = "dest";
**  	char	src[100] = "src";
**
**  	printf("ft_strlcat = >%zu<\n", ft_strlcat(ft_dst, ft_src, 0));
**  	printf("   strlcat = >%zu<\n", strlcat(dst, src, 0));
**  	printf("ft_dst = \"%s\"\n", ft_dst);
**  	printf("   dst = \"%s\"\n", dst);
**  	return (0);
**  }
*/
