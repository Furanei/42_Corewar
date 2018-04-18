../objects/secure_define.o: ../sources/secure_define.c \
  ../includes/secure_define.h ../includes/mem.h ../includes/op.h \
  ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/secure_define.c -o ../objects/secure_define.o
	@echo "\033[0;33m""created: ../objects/secure_define.o""\033[m"

