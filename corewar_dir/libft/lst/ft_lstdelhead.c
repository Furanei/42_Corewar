/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelhead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:15:28 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:28:06 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelhead(t_list **old_head, void (*del)(void *, size_t))
{
	t_list	*new_head;

	if (old_head != NULL)
	{
		if (*old_head != NULL)
		{
			new_head = (*old_head)->next;
			(*del)(((**old_head).content), (**old_head).content_size);
			ft_memdel((void **)old_head);
			*old_head = new_head;
		}
	}
}
