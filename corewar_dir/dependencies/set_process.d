../objects/set_process.o: ../sources/set_process.c \
  ../includes/set_process.h ../includes/mem.h ../includes/op.h \
  ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/set_process.c -o ../objects/set_process.o
	@echo "\033[0;33m""created: ../objects/set_process.o""\033[m"

