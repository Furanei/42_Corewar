../objects/fork_e.o: ../sources/fork_e.c ../includes/fork_e.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h \
  ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/fork_e.c -o ../objects/fork_e.o
	@echo "\033[0;33m""created: ../objects/fork_e.o""\033[m"

