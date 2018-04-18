../objects/change_op.o: ../sources/change_op.c ../includes/change_op.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h \
  ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/change_op.c -o ../objects/change_op.o
	@echo "\033[0;33m""created: ../objects/change_op.o""\033[m"

