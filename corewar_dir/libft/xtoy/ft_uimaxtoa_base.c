/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:27:20 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:43:56 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uimaxtoa_base(uintmax_t n, int base)
{
	char		*result;
	size_t		len_result;
	uintmax_t	temp_n;

	temp_n = n;
	len_result = ((n == 0) ? 1 : 0);
	while (temp_n != 0)
	{
		len_result++;
		temp_n /= base;
	}
	if ((result = ft_strnew(len_result)) == NULL)
		return (NULL);
	while (len_result > 0)
	{
		if ((n % base) <= 9)
			result[--len_result] = '0' + (n % base);
		else
			result[--len_result] = 'a' - (char)10 + (n % base);
		n /= base;
	}
	return (result);
}
