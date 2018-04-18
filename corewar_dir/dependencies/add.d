../objects/add.o: ../sources/add.c ../includes/add.h ../libft/libft.h \
  ../includes/mem.h ../includes/op.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/add.c -o ../objects/add.o
	@echo "\033[0;33m""created: ../objects/add.o""\033[m"

