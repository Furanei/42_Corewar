../objects/xor.o: ../sources/xor.c ../includes/xor.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/xor.c -o ../objects/xor.o
	@echo "\033[0;33m""created: ../objects/xor.o""\033[m"

