/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 07:43:03 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:44:02 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa(unsigned int n)
{
	char	*result;
	size_t	len_result;
	int		temp_n;

	len_result = ((n == 0) ? 1 : 0);
	temp_n = n;
	while (temp_n != 0)
	{
		len_result++;
		temp_n /= 10;
	}
	if ((result = ft_strnew(len_result)) == NULL)
		return (NULL);
	while (len_result > 0)
	{
		result[--len_result] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
