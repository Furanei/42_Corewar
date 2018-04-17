/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:12:42 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:28:59 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp_alst;

	if (lst != NULL)
	{
		temp_alst = ft_lstmap((*lst).next, f);
		ft_lstadd(&temp_alst, (*f)(lst));
		return (temp_alst);
	}
	else
		return (NULL);
}
