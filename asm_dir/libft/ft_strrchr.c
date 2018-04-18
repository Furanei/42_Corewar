/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:21 by mbenjell          #+#    #+#             */
/*   Updated: 2018/02/07 01:32:08 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*s_init;
	int		n;

	s_init = (char*)s;
	n = ft_strlen(s);
	while (n--)
		s_init++;
	while (*s_init != (char)c && s != s_init)
		s_init--;
	if (*s_init == (char)c)
		return ((char*)s_init);
	return (NULL);
}
