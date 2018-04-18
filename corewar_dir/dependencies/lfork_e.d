../objects/lfork_e.o: ../sources/lfork_e.c ../includes/lfork_e.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h \
  ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/lfork_e.c -o ../objects/lfork_e.o
	@echo "\033[0;33m""created: ../objects/lfork_e.o""\033[m"

