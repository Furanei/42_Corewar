/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 04:30:57 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/13 02:44:44 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	generate_name_cor(t_data *d)
{
	char	*name_cor;
	size_t	len_input;
	size_t	len_base_name;
	size_t	len;

	len_input = ft_strlen(d->file_s);
	len_base_name = len_input - ft_strlen(EXT_INPUT_FILE);
	len = len_base_name + ft_strlen(EXT_OUTPUT_FILE);
	name_cor = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (name_cor == NULL && (d->error = MALLOC_FAILED))
		return (ERROR);
	ft_strncpy(name_cor, d->file_s, len_base_name);
	d->file_cor = name_cor;
	name_cor += len_base_name;
	ft_strcpy(name_cor, EXT_OUTPUT_FILE);
	return (SUCCESS);
}

int			file_name(t_data *d)
{
	char	*name_s;
	size_t	len_name;
	int		ret;

	name_s = d->file_s;
	len_name = ft_strlen(name_s);
	if (len_name <= ft_strlen(EXT_INPUT_FILE) && (d->error = E_NAME_FILE))
		return (ERROR);
	if (len_name > NAME_FILE_MAX && (d->error = E_NAME_LONG))
		return (ERROR);
	while (*name_s)
		name_s++;
	name_s -= ft_strlen(EXT_INPUT_FILE);
	if (!ft_strequ(name_s, EXT_INPUT_FILE) && (d->error = E_EXT_FILE))
		return (ERROR);
	ret = generate_name_cor(d);
	if (ret == ERROR)
		return (ERROR);
	return (SUCCESS);
}
