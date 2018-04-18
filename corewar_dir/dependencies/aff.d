../objects/aff.o: ../sources/aff.c ../includes/aff.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/aff.c -o ../objects/aff.o
	@echo "\033[0;33m""created: ../objects/aff.o""\033[m"

