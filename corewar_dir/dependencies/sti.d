../objects/sti.o: ../sources/sti.c ../includes/sti.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/sti.c -o ../objects/sti.o
	@echo "\033[0;33m""created: ../objects/sti.o""\033[m"

