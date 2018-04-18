objects/tools.o: sources/tools.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/tools.c -o objects/tools.o
	@echo "\033[0;33m""created: objects/tools.o""\033[m"

