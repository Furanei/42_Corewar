../objects/or.o: ../sources/or.c ../includes/or.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/or.c -o ../objects/or.o
	@echo "\033[0;33m""created: ../objects/or.o""\033[m"

