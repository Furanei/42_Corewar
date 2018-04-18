../objects/set_champ.o: ../sources/set_champ.c ../includes/set_champ.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/set_champ.c -o ../objects/set_champ.o
	@echo "\033[0;33m""created: ../objects/set_champ.o""\033[m"

