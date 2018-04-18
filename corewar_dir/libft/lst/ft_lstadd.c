/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:20 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:27:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	**old_head;
	t_list	*new_head;

	old_head = alst;
	new_head = new;
	if (old_head != NULL)
	{
		(*new_head).next = *old_head;
		*old_head = new_head;
	}
}
