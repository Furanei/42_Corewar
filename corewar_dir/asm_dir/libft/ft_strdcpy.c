/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:00:48 by mbenjell          #+#    #+#             */
/*   Updated: 2018/03/24 18:34:04 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdcpy(char *dest, const char *src, char *c)
{
	char	*dest_init;

	dest_init = dest;
	while (*src)
	{
		if (!ft_strchr(c, *src))
			*dest++ = *src++;
		else
			src++;
	}
	*dest = '\0';
	return (dest_init);
}
