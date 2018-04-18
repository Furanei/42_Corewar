../objects/dump.o: ../sources/dump.c ../includes/dump.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/dump.c -o ../objects/dump.o
	@echo "\033[0;33m""created: ../objects/dump.o""\033[m"

