../objects/and.o: ../sources/and.c ../includes/and.h ../libft/libft.h \
  ../includes/mem.h ../includes/op.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/and.c -o ../objects/and.o
	@echo "\033[0;33m""created: ../objects/and.o""\033[m"

