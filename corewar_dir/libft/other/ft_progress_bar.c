/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress_bar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:37:32 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:34:39 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  the progress bar is on 52 char and the sting on 2 + (3 * 50) = 152
**  c[2] =     ??? ??? = '½'
**  c[3] = 226 160 128 = '⠀';
**  c[3] = 226 161 128 = '⡀';
**  c[3] = 226 161 132 = '⡄';
**  c[3] = 226 161 134 = '⡆';
**  c[3] = 226 161 135 = '⡇';
**  c[3] = 226 161 143 = '⡏';
**  c[3] = 226 161 159 = '⡟';
**  c[3] = 226 161 191 = '⡿'
**  c[3] = 226 163 191 = '⣿';
**  1 dot = 0.25 % (50 * '⣿' == 100 %)
*/

static void		init(char str[153], int *e, int *j)
{
	int		i;

	str[0] = ' ';
	str[1] = '[';
	str[152] = ']';
	str[153] = '\r';
	i = 2;
	while (i < 151)
	{
		str[i++] = (char)226;
		str[i++] = (char)160;
		str[i++] = (char)128;
	}
	while (*e >= 8)
	{
		str[(*j)++] = (char)226;
		str[(*j)++] = (char)163;
		str[(*j)++] = (char)191;
		*e -= 8;
	}
}

void			ft_progress_bar(int current_state, int max)
{
	char	str[154];
	int		e;
	int		j;

	j = 2;
	e = 400 * current_state / max;
	init(str, &e, &j);
	str[j + 1] = (char)161;
	if (e == 7)
		str[j + 2] = (char)191;
	else if (e == 6)
		str[j + 2] = (char)159;
	else if (e == 5)
		str[j + 2] = (char)143;
	else if (e == 4)
		str[j + 2] = (char)135;
	else if (e == 3)
		str[j + 2] = (char)134;
	else if (e == 2)
		str[j + 2] = (char)132;
	else if (e == 1)
		str[j + 2] = (char)128;
	else
		str[j + 1] = (char)160;
	write(1, str, 154);
}
