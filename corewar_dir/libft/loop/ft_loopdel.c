/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:31:18 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 14:03:50 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopdel(t_loop **aloop, void (*del)(void *, size_t))
{
	if (aloop != NULL)
		while (*aloop != NULL)
			ft_loopdelhead(aloop, del);
}
