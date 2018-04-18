objects/parser.o: sources/parser.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/parser.c -o objects/parser.o
	@echo "\033[0;33m""created: objects/parser.o""\033[m"

