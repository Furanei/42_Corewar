# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 00:10:02 by mbenjell          #+#    #+#              #
#    Updated: 2018/04/17 08:41:46 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= asm

HEAD		:= asm.h

FILES		:= tools \
			extract \
			argument \
			value \
			instruction \
			checker \
			label \
			header \
			parser \
			calculus \
			writer \
			file \
			error \
			free \
			op \
			asm

PRINTF		:= ./ft_printf/libftprintf.a

RM			:= /bin/rm

LIBFT_DIR	:= libft/
SRC_DIR		:= sources/
OBJ_DIR		:= objects/
DEP_DIR		:= objects/

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
DEP			:= $(addprefix $(DEP_DIR), $(addsuffix .d, $(FILES)))

LIB_FLAGS	:= -L./ft_printf/ -lftprintf -L$(LIBFT_DIR) -lft

GCC_FLAGS	:= -Wall -Wextra -Werror -I./ -I$(LIBFT_DIR) -I./ft_printf/        \
#			-g -fsanitize=address

.PHONY:	all leaks clean fclean re norme always_do_it

all: $(NAME)

leaks:
	leaks $(NAME)

$(LIBFT_DIR)libft.a always_do_it:
	@make libft.a -C $(LIBFT_DIR)

./ft_printf/libftprintf.a: always_do_it
	@make libftprintf.a -C ./ft_printf/

$(NAME): $(LIBFT_DIR)libft.a ft_printf/libftprintf.a $(OBJ)
	@gcc $(GCC_FLAGS) $(LIB_FLAGS) $^ -o $@
	@echo "\033[0;32m""created: $@""\033[m"
	@echo "\033[1;36m""flags i use are ""\033[0;36m""$(GCC_FLAGS)""\033[m"
	@echo "\033[1;36m""and ""\033[0;36m""$(LIB_FLAGS)""\033[1;36m"" too, ""\c"
	@echo "but only when i link $@""\033[m"

$(OBJ_DIR)%.o: $(DEP_DIR)%.d
	@make $@ -f $^

$(DEP_DIR)%.d: $(SRC_DIR)%.c always_do_it
	@mkdir -p $(DEP_DIR) 2> /tmp/a.del
	@mkdir -p $(OBJ_DIR) 2> /tmp/a.del
	@echo ""                                                               >  $@
	@echo ".PHONY:"                                                        >> $@
	@echo ""                                                               >> $@
	@echo "$(OBJ_DIR)\c"                                                   >> $@
	@gcc $(GCC_FLAGS) -MM $(@:$(DEP_DIR)%d=$(SRC_DIR)%c)                   >> $@
	@echo "	@gcc $(GCC_FLAGS) -c $< -o $(@:$(DEP_DIR)%d=$(OBJ_DIR)%o)"     >> $@
	@echo "	@echo \"\\\033[0;33m\"\"\c"                                    >> $@
	@echo "created: $(@:$(DEP_DIR)%d=$(OBJ_DIR)%o)\"\c"                    >> $@
	@echo "\"\\\033[m\""                                                   >> $@
	@echo ""                                                               >> $@
#	@cat $@

clean:
	@echo "\033[0;31m""deleted all these files :""\033[m"
	@make $@ -C $(LIBFT_DIR)
	@make $@ -C ./ft_printf/
	@echo "\033[1;31m""\c"
	@$(RM) -fv $(OBJ) | column
	@$(RM) -dv $(OBJ_DIR) | column
	@echo "\033[m""\c"

fclean:
	@make clean -f Makefile -C .
	@make $@ -C $(LIBFT_DIR)
	@make $@ -C ./ft_printf/
	@echo "\033[0;31m""\c"
	@$(RM) -fv $(NAME)
	@echo "\033[m""\c"

re:
	@make fclean
	@make all

norme:
	@echo "\033[1;37m""norminette on $(SRC_DIR)""\033[m"
	@norminette $(SRC_DIR)                               \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[0;32mNorme"`/g''
	@echo "\033[1;37m""norminette on $(HEAD)""\033[m"
	@norminette $(HEAD)                               \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[1;34mNorme"`/g''
	@echo "\033[m""\c"
