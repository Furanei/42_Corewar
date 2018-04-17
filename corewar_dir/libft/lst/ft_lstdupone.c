/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:26:26 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/08 00:42:31 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdupone(t_list *elem)
{
	if (elem == NULL)
		return (NULL);
	else
		return (ft_lstnew(elem->content, elem->content_size));
}
