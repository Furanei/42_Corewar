../objects/zjmp.o: ../sources/zjmp.c ../includes/zjmp.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/zjmp.c -o ../objects/zjmp.o
	@echo "\033[0;33m""created: ../objects/zjmp.o""\033[m"

