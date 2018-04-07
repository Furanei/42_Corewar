/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:54:03 by mbenjell          #+#    #+#             */
/*   Updated: 2018/02/18 15:16:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*elt;

	if ((elt = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
