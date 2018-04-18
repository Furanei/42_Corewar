../objects/set_options.o: ../sources/set_options.c \
  ../includes/set_options.h ../includes/mem.h ../includes/op.h \
  ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/set_options.c -o ../objects/set_options.o
	@echo "\033[0;33m""created: ../objects/set_options.o""\033[m"

