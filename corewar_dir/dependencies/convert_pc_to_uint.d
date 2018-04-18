../objects/convert_pc_to_uint.o: ../sources/convert_pc_to_uint.c \
  ../includes/convert_pc_to_uint.h ../includes/mem.h ../includes/op.h \
  ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/convert_pc_to_uint.c -o ../objects/convert_pc_to_uint.o
	@echo "\033[0;33m""created: ../objects/convert_pc_to_uint.o""\033[m"

