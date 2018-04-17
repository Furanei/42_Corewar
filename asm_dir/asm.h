/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:23:26 by mbenjell          #+#    #+#             */
/*   Updated: 2018/04/17 04:43:36 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define MALLOC_FAILED			2
# define E_TYPE					3
# define E_LABEL				4
# define E_LABEL_NOT_FOUND 		5
# define E_VIRGULE				6
# define E_INSTR				7
# define E_NUMBER				8
# define E_QUOTE				9
# define E_LONG_NAME			10
# define E_LONG_COMM			11
# define E_BAD_HEADER			12
# define E_INC_HEADER			13
# define E_NAME_FILE			14
# define E_EXT_FILE				15
# define E_NAME_LONG			16
# define E_OPEN_FILE			17
# define E_ARG					18
# define E_NO_ARG				19

# define T1						0xC901
# define T2						0x1006
# define T3						0x26F8

# define T_REG_1				0xA6FC
# define T_REG_2				0x36FE
# define T_REG_3				0x26F8

# define T_DIR_1				0x7BE3
# define T_DIR_2				0x26E0
# define T_DIR_3				0x400

# define T_IND_1				0x32E2
# define T_IND_2				0x4E4

# define P_HEADER				1
# define P_INSTR				2

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define QUOTE_CHAR				'\"'

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_STRING			".name"
# define COMMENT_STRING			".comment"

# define REG_NUMBER				16

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define NAME_FILE_MAX			255

# define EXT_INPUT_FILE			".s"
# define EXT_OUTPUT_FILE		".cor"

typedef	struct					s_op
{
	char						*name;
	unsigned int				number_of_parameters;
	unsigned int				type_of_parameters[4];
	unsigned char				opcode;
	unsigned int				cycle_duration;
	char						*description;
	int							boolean_argument_coding_byte;
	int							boolean_length_direct;
}								t_op;

typedef	struct					s_data
{
	int							state;
	int							fd;
	int							fd_cor;
	char						*file_s;
	char						*file_cor;
	char						prog_name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
	int							get_name;
	int							get_comment;
	char						*buff;
	char						*line;
	char						*line_arg;
	int							opcode;
	size_t						nb_line;
	unsigned int				lg_champion;
	unsigned int				pc;
	char						**arg;
	int							type[3];
	int							value[3];
	char						*label_name;
	int							active_lab;
	int							error;
	struct s_instr				*instr;
	struct s_label				*label;
}								t_data;

typedef struct					s_instr
{
	size_t						line;
	unsigned int				pc;
	unsigned int				lg;
	int							opcode;
	int							nb_arg;
	int							ocp;
	char						**arg;
	int							type[3];
	int							value[3];
	struct s_instr				*next;
}								t_instr;

typedef struct					s_label
{
	size_t						line;
	char						*name;
	t_instr						*instr;
	struct s_label				*next;
}								t_label;

int								is_space(char **c);
void							speed_space(char **c);
int								ft_watoi(char **nptr, int *res);
int								ft_catoi(char *nptr, int *res);

int								extract_header(t_data *d);
int								extract_instr(t_data *d);
int								extract_types(t_data *d);
int								extract_values(t_data *d);
int								extract_label(t_data *d);

int								add_instr(t_data *d);
void							reverse_instr(t_data *d);
void							reverse_label(t_data *d);

int								parser(t_data *d);
int								checker(t_instr *instr);
int								writer(t_data *d);

void							lg_instr(t_instr *i);
void							lg_champion(t_data *d);
int								calcul_ocp(t_instr *i);
int								calcul_label(t_data *d, t_instr *i, int n);
int								replace_labels(t_data *d);

int								file_name(t_data *d);
void							print_error(t_data *d);
int								ft_error(t_data *d);
int								ft_usage(void);

void							free_data(t_data *d);

extern t_op						g_op_tab[17];

#endif
