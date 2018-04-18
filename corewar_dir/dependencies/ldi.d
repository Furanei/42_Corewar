../objects/ldi.o: ../sources/ldi.c ../includes/ldi.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/ldi.c -o ../objects/ldi.o
	@echo "\033[0;33m""created: ../objects/ldi.o""\033[m"

