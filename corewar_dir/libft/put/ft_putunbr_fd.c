/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:29:49 by enanrock          #+#    #+#             */
/*   Updated: 2017/10/09 00:06:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
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
		temp_n /= 10;
	}
	while (len_result > 0)
	{
		result[--len_result] = '0' + (n % 10);
		n /= 10;
	}
	ft_putstr_fd(result, fd);
}
