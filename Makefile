# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2018/04/18 22:31:48 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= corewar
NAME_001	:= $(NAME)
NAME_002	:= asm
NAME_ALL	:= $(NAME_001) $(NAME_002)

DIR_001		:= ./$(NAME_001)_dir/
DIR_002		:= ./$(NAME_002)_dir/

.PHONY:	all clean fclean re norme leaks reset tuto tuto_corewar always_do_it

all: auteur .gitignore $(NAME_ALL)

$(NAME_001): auteur .gitignore always_do_it
	@make $@ -C $(DIR_001)
	@cp $(DIR_001)$(NAME_001) $(NAME_001)

$(NAME_002): auteur .gitignore always_do_it
	@make $@ -C $(DIR_002)
	@cp $(DIR_002)$(NAME_002) $(NAME_002)

clean:
	@make $@ -C $(DIR_001)
	@make $@ -C $(DIR_002)

fclean:
	@rm -f $(NAME_001) $(DIR_001)$(NAME_001)
	@rm -f $(NAME_002) $(DIR_002)$(NAME_002)
	@make $@ -C $(DIR_001)
	@make $@ -C $(DIR_002)

re:
	@make fclean
	@make all

norme:
	@make $@ -C $(DIR_001)
	@make $@ -C $(DIR_002)

auteur:
	@echo "\033[1;37m""\c"
	echo "enanrock"  > auteur
	echo "mbenjell" >> auteur
	echo "mbriffau" >> auteur
	@echo "\033[m"

.gitignore:
	@echo "\033[1;37m""\c"
	echo "$(NAME_001)"   > $@
	echo "$(NAME_002)"  >> $@
	echo "dependencies" >> $@
	echo "objects"      >> $@
	echo "*.swp"        >> $@
	echo "*.o"          >> $@
	echo "*.a"          >> $@
	echo "*.d"          >> $@
	echo "*.cor"        >> $@
	echo "*_DONE"       >> $@
	echo "*.dSYM/"      >> $@
	@echo "\033[m"

leaks:
	clear
	leaks $(NAME_001)
	leaks $(NAME_002)

reset:
	rm -Rf auteur
	rm -Rf .gitignore
	@make $@ -C $(DIR_001)

tuto:
	@echo "do make tuto_corewar"

tuto_corewar:
	@make $@ -C $(DIR_001)
