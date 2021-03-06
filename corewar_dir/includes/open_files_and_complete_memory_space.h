/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_complete_memory_space.h             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:23:17 by enanrock          #+#    #+#             */
/*   Updated: 2018/04/19 17:56:40 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_FILES_AND_COMPLETE_MEMORY_SPACE_H
# define OPEN_FILES_AND_COMPLETE_MEMORY_SPACE_H

# include <fcntl.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "mem.h"
# include "check_the_header.h"

int		open_files_and_complete_memory_space(t_mem *mem);

#endif
