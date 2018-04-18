../objects/live.o: ../sources/live.c ../includes/live.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/live.c -o ../objects/live.o
	@echo "\033[0;33m""created: ../objects/live.o""\033[m"

