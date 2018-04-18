../objects/test_argument_coding_bytes.o: \
  ../sources/test_argument_coding_bytes.c \
  ../includes/test_argument_coding_bytes.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/test_argument_coding_bytes.c -o ../objects/test_argument_coding_bytes.o
	@echo "\033[0;33m""created: ../objects/test_argument_coding_bytes.o""\033[m"

