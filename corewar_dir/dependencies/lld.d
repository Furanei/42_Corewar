../objects/lld.o: ../sources/lld.c ../includes/lld.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/lld.c -o ../objects/lld.o
	@echo "\033[0;33m""created: ../objects/lld.o""\033[m"

