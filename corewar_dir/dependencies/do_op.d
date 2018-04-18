../objects/do_op.o: ../sources/do_op.c ../includes/do_op.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h \
  ../includes/convert_pc_to_uint.h \
  ../includes/test_argument_coding_bytes.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/do_op.c -o ../objects/do_op.o
	@echo "\033[0;33m""created: ../objects/do_op.o""\033[m"

