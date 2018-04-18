../objects/lldi.o: ../sources/lldi.c ../includes/lldi.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/lldi.c -o ../objects/lldi.o
	@echo "\033[0;33m""created: ../objects/lldi.o""\033[m"

