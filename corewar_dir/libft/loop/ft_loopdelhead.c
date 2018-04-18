/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopdelhead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:15:28 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 14:04:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopdelhead(t_loop **old_head, void (*del)(void *, size_t))
{
	t_loop	*new_head;

	if (old_head != NULL)
	{
		if (*old_head != NULL)
		{
			new_head = (**old_head).down;
			if (new_head == (*old_head))
				new_head = NULL;
			else
			{
				(*(**old_head).down).up = (**old_head).up;
				(*(**old_head).up).down = (**old_head).down;
			}
			(*del)(((**old_head).content), (**old_head).content_size);
			ft_memdel((void **)old_head);
			*old_head = new_head;
		}
	}
}
