/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 03:42:56 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 23:32:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_error_a(t_data *d)
{
	ft_printf(2, "Ligne [%d] : ", d->nb_line + 1);
	if (d->error == E_TYPE)
		ft_printf(2, "Erreur de typage\n");
	if (d->error == E_LABEL)
		ft_printf(2, "Label invalide\n");
	if (d->error == E_LABEL_NOT_FOUND)
		ft_printf(2, "Label inexistant\n");
	if (d->error == E_VIRGULE)
		ft_printf(2, "Présence de plus de 2 '%c'\n", SEPARATOR_CHAR);
	if (d->error == E_INSTR)
		ft_printf(2, "Instruction invalide\n");
	if (d->error == E_NUMBER)
		ft_printf(2, "Nombre invalide\n");
	if (d->error == E_QUOTE)
		ft_printf(2, "Guillemet manquant\n");
	if (d->error == E_LONG_NAME)
		ft_printf(2, "Nom trop long\n");
	if (d->error == E_LONG_COMM)
		ft_printf(2, "Commentaire trop long\n");
	if (d->error == E_BAD_HEADER)
		ft_printf(2, "Défaut dans la déclaration du header\n");
}

void		print_error_b(t_data *d)
{
	if (d->error == MALLOC_FAILED)
		ft_printf(2, "Allocation mémoire échouée\n");
	if (d->error == E_INC_HEADER)
		ft_printf(2, "Header incomplet\n");
	if (d->error == E_NAME_FILE)
		ft_printf(2, "Nom de fichier trop court\n");
	if (d->error == E_EXT_FILE)
		ft_printf(2, "Extension fichier incorrecte ('%s')\n", EXT_INPUT_FILE);
	if (d->error == E_NAME_LONG)
		ft_printf(2, "Nom fichier trop long\n");
	if (d->error == E_OPEN_FILE)
		ft_printf(2, "Échec ouverture fichier ('%s')\n", d->file_s);
	if (d->error == E_ARG)
		ft_printf(2, "Argument invalide\n");
	if (d->error == E_NO_ARG)
		ft_printf(2, "Absence d'arguments\n");
	if (d->error == E_BAD_REG)
		ft_printf(2, "Numéro de registre invalide\n");
}

void		print_error(t_data *d)
{
	print_error_a(d);
	print_error_b(d);
}

int			ft_error(t_data *d)
{
	print_error(d);
	free_data(d);
	return (ERROR);
}

int			ft_usage(void)
{
	ft_printf(2, "Usage : ./asm [file_name]%s\n", EXT_INPUT_FILE);
	return (ERROR);
}
