../objects/help_corewar.o: ../sources/help_corewar.c \
  ../includes/help_corewar.h ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/help_corewar.c -o ../objects/help_corewar.o
	@echo "\033[0;33m""created: ../objects/help_corewar.o""\033[m"

