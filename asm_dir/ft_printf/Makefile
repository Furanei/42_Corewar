# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/04 13:31:13 by mbenjell          #+#    #+#              #
#    Updated: 2018/04/17 08:47:19 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

SRC		:= tools.c \
		buffer.c \
		argument.c \
		format.c \
		format_unicode.c \
		conversion.c \
		writer.c \
		unicode.c \
		unicode_tools.c \
		ft_printf.c

FLAG	:= -Wall -Werror -Wextra

RM		:= /bin/rm -rf

OBJ		:= $(addsuffix .o, $(basename $(SRC)))

.PHONY:	all clean fclean re

all: $(NAME)

%.o : %.c
	@echo "\033[1;33m\c"
	gcc -c $(FLAG) -o $@ $^
	@echo "\033[m\c"

$(NAME): $(OBJ) ft_printf.h
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
