objects/argument.o: sources/argument.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/argument.c -o objects/argument.o
	@echo "\033[0;33m""created: objects/argument.o""\033[m"

