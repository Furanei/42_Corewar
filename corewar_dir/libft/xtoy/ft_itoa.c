/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:27:20 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:43:47 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	size_t	len_result;
	int		temp_n;

	is_negative = (n < 0) ? 1 : 0;
	n *= (n < 0) ? 1 : -1;
	len_result = ((n == 0) ? 1 : 0) + is_negative;
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
		result[--len_result] = '0' - (n % 10);
		n /= 10;
	}
	if (is_negative == 1)
		result[0] = '-';
	return (result);
}
