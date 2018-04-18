../objects/sub.o: ../sources/sub.c ../includes/sub.h ../libft/libft.h \
  ../includes/mem.h ../includes/op.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/sub.c -o ../objects/sub.o
	@echo "\033[0;33m""created: ../objects/sub.o""\033[m"

