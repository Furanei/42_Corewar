/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongchar_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:25:35 by enanrock          #+#    #+#             */
/*   Updated: 2017/11/03 13:35:17 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_is_1_or_2(int c, int fd)
{
	char	to_write;

	if ((0 <= c) && (c <= 127))
	{
		to_write = c;
		write(fd, &to_write, 1);
	}
	if ((128 <= c) && (c <= 2047))
	{
		to_write = (char)(192 + ((c / 64) % 32));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 1) % 64));
		write(fd, &to_write, 1);
	}
}

static void		write_is_3_or_4(int c, int fd)
{
	char	to_write;

	if ((2048 <= c) && (c <= 65535))
	{
		to_write = (char)(224 + ((c / 4096) % 16));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 64) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 1) % 64));
		write(fd, &to_write, 1);
	}
	if ((65536 <= c) && (c <= 2097151))
	{
		to_write = (char)(240 + ((c / 262144) % 8));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 4096) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 64) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 1) % 64));
		write(fd, &to_write, 1);
	}
}

static void		write_is_5(int c, int fd)
{
	char	to_write;

	if ((2097152 <= c) && (c <= 67108863))
	{
		to_write = (char)(248 + ((c / 16777216) % 4));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 262144) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 4096) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 64) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 1) % 64));
		write(fd, &to_write, 1);
	}
}

static void		write_is_6(int c, int fd)
{
	char	to_write;

	if ((67108864 <= c) && (c <= 2147483647))
	{
		to_write = (char)(252 + ((c / 1073741824) % 2));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 16777216) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 262144) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 4096) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 64) % 64));
		write(fd, &to_write, 1);
		to_write = (char)(128 + ((c / 1) % 64));
		write(fd, &to_write, 1);
	}
}

void			ft_putlongchar_fd(int c, int fd)
{
	write_is_1_or_2(c, fd);
	write_is_3_or_4(c, fd);
	write_is_5(c, fd);
	write_is_6(c, fd);
}

/*
**  example
**  1) input : c = 1 0010 0011 0100 (= 4660)
**  2) where can i put C ?
**  (sizeof(wchar_t) = sizeof(int) = 4)
**           0        127 - 0XXXXXXX
**         128       2047 - 110XXXXX 10XXXXXX
**        2048      65535 > 1110XXXX 10XXXXXX 10XXXXXX
**       65536    2097151 - 11110XXX 10XXXXXX 10XXXXXX 10XXXXXX
**     2097152   67108863 - 111110XX 10XXXXXX 10XXXXXX 10XXXXXX 10XXXXXX
**    67108864 2147483647 - 1111110X 10XXXXXX 10XXXXXX 10XXXXXX 10XXXXXX etc
**   int_max = 2147483647
**  3) put C :              1110oooo 10oooooo 10oooooo
**                        + oooo   1 oo001000 oo110100
**  4) 3 writes :          (11100001 10001000 10110100)
**
**  fail with : 55296 to 57343
**  and from 1114111 to infinit
*/
