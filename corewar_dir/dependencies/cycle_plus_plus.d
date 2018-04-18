../objects/cycle_plus_plus.o: ../sources/cycle_plus_plus.c \
  ../includes/cycle_plus_plus.h ../includes/mem.h ../includes/op.h \
  ../libft/libft.h ../includes/change_op.h \
  ../includes/convert_pc_to_uint.h ../includes/do_op.h \
  ../includes/test_argument_coding_bytes.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/cycle_plus_plus.c -o ../objects/cycle_plus_plus.o
	@echo "\033[0;33m""created: ../objects/cycle_plus_plus.o""\033[m"

