/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:55:28 by enanrock          #+#    #+#             */
/*   Updated: 2018/02/13 17:00:50 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int n, int fd)
{
	char			result[12];
	size_t			len_result;
	unsigned int	temp_n;

	ft_memset(result, '\0', 12 * sizeof(char));
	len_result = (n == 0) ? 1 : 0;
	temp_n = n;
	while (temp_n != 0)
	{
		len_result++;
		temp_n /= 16;
	}
	while (len_result > 0)
	{
		result[--len_result] = (n % 16);
		if ((0 <= result[len_result]) && (result[len_result] <= 9))
			result[len_result] += '0';
		else
			result[len_result] += 'a' - 10;
		n /= 16;
	}
	ft_putstr_fd(result, fd);
}
