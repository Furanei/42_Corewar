/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:08:01 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/25 17:38:29 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	len;

	if (s != NULL)
	{
		i = 0;
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			i++;
		start = (unsigned int)i;
		i = ft_strlen((char *)s) - 1;
		while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
				&& (i > start))
			i--;
		len = i - start + 1;
		return (ft_strsub(s, (unsigned int)start, len));
	}
	else
		return (NULL);
}
