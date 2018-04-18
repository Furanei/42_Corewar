/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:07:50 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 23:06:56 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_octets(int fd, unsigned int v, int o)
{
	if (o == 4)
	{
		ft_printf(fd, "%c%c%c%c",
			(v / 0x1000000) % 0x100,
			(v / 0x10000) % 0x100,
			(v / 0x100) % 0x100,
			(v / 0x1) % 0x100);
	}
	else if (o == 2)
	{
		ft_printf(fd, "%c%c",
			(v / 0x100) % 0x100,
			(v / 0x1) % 0x100);
	}
	else if (o == 1)
		ft_printf(fd, "%c", v % 0x100);
}

static void		write_value(t_instr *i, int fd)
{
	int			nb_arg;
	int			id;
	int			v;

	id = i->opcode;
	nb_arg = 0;
	while (nb_arg < i->nb_arg)
	{
		v = i->value[nb_arg];
		if (i->type[nb_arg] & T_DIR)
		{
			if (g_op_tab[id - 1].boolean_length_direct == 0)
				print_octets(fd, v, 4);
			else
				print_octets(fd, v, 2);
		}
		else if (i->type[nb_arg] & T_IND)
			print_octets(fd, v, 2);
		else
			print_octets(fd, v, 1);
		nb_arg++;
	}
}

static void		write_instr(t_instr *i, int fd)
{
	int			id;

	id = i->opcode;
	print_octets(fd, id, 1);
	if (g_op_tab[id - 1].boolean_argument_coding_byte == 1)
	{
		calcul_ocp(i);
		print_octets(fd, i->ocp, 1);
	}
	write_value(i, fd);
}

static void		write_header(t_data *d)
{
	int			fd;
	int			left;

	fd = d->fd_cor;
	print_octets(fd, COREWAR_EXEC_MAGIC, 4);
	ft_printf(fd, "%s", d->prog_name);
	left = PROG_NAME_LENGTH - ft_strlen(d->prog_name);
	while (left--)
		print_octets(fd, 0, 1);
	print_octets(fd, 0, 4);
	print_octets(fd, d->lg_champion, 4);
	ft_printf(fd, "%s", d->comment);
	left = COMMENT_LENGTH - ft_strlen(d->comment);
	while (left--)
		print_octets(fd, 0, 1);
	print_octets(fd, 0, 4);
}

int				writer(t_data *d)
{
	t_instr		*i;

	d->fd_cor = open(d->file_cor, O_CREAT | O_WRONLY, 0644);
	if (d->fd_cor == -1)
		return (ERROR);
	lg_champion(d);
	write_header(d);
	i = d->instr;
	while (i)
	{
		write_instr(i, d->fd_cor);
		i = i->next;
	}
	ft_printf(0, "Écriture de la sortie du programme dans %s\n", d->file_cor);
	ft_close(&d->fd_cor);
	return (SUCCESS);
}
