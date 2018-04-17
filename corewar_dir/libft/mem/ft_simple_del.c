/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:14:59 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:33:08 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_simple_del(void *content, size_t len)
{
	size_t	i;
	char	*temp_content;

	if (content != NULL)
	{
		temp_content = content;
		i = 0;
		while (i < len)
			temp_content[i++] = 0;
		ft_memdel(&content);
	}
}
