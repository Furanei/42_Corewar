../objects/ld.o: ../sources/ld.c ../includes/ld.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/ld.c -o ../objects/ld.o
	@echo "\033[0;33m""created: ../objects/ld.o""\033[m"

