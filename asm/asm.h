/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:23:26 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/05 21:57:53 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				ASM_H
# define			ASM_H

# include <fcntl.h>
# include "op.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define T1			0xC901
# define T2			0x1006
# define T3			0x26F8

# define T_REG_1	0xA6FC
# define T_REG_2	0x36FE
# define T_REG_3	0x26F8

# define T_DIR_1	0x7BE3
# define T_DIR_2	0x26E0
# define T_DIR_3	0x400

# define T_IND_1 	0x32E2
# define T_IND_2 	0x4E4
# define T_IND_3

# define P_HEADER	1
# define P_INSTR	2

extern t_op			g_op_tab[17];

typedef	struct		s_data
{
	int				state;
	int				fd;
	char			*buff;
	char			*line;
	char			*line_arg;
	int 			opcode;
	size_t			nb_line;
	char			**arg;
	int				type[3];
	int				value[3];
	char			*label_name;
	int 			active_lab;
	int				error;
	struct s_instr	*instr;
	struct s_label	*label;
}					t_data;

typedef struct		s_instr
{
	int				opcode;
	int				nb_arg;
	int				ocp;
	char			**arg;
	int				type[3];
	int				value[3];
	struct s_instr	*next;
}					t_instr;

typedef struct		s_label
{
	char			*name;
	t_instr			*instr;
	struct s_label	*next;
}					t_label;

int					is_space(char **c);
int					ft_watoi(char **nptr, int *res);
int					ft_catoi(char *nptr, int *res);

int					extract_header(t_data *d);
int					extract_instr(t_data *d);
int					extract_types(t_data *d);
int					extract_values(t_data *d);
int					extract_label(t_data *d);

int					add_instr(t_data *d);

int					parser(t_data *d);
int					checker(t_instr *instr);
int					writer(t_instr *instr);

void				display_instr(t_data *d);
void 				display_label(t_data *d);

#endif
