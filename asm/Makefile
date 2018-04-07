# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 00:10:02 by mbenjell          #+#    #+#              #
#    Updated: 2018/04/05 06:37:21 by mbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

HEAD = asm.h

SRC =	tools.c \
		extract.c \
		argument.c \
		value.c \
		instruction.c \
		checker.c \
		label.c \
		parser.c \
		asm.c \
		op.c \
		debug.c \

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

FLAG = -Wall -Werror -Wextra

RM = /bin/rm -rf

OBJ = $(addsuffix .o, $(basename $(SRC)))

.PHONY: all clean fclean re

all: $(NAME)

%.o : %.c
	gcc -c $(FLAG) -o $@ $^

$(NAME): $(OBJ) $(HEAD)
		@make -C libft
		@make -C ft_printf
		@gcc $(FLAG) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -C libft
		@make clean -C ft_printf

fclean:	clean
		@$(RM) $(NAME)
		@make fclean -C libft
		@make fclean -C ft_printf

re:		fclean all
