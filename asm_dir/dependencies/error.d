objects/error.o: sources/error.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/error.c -o objects/error.o
	@echo "\033[0;33m""created: objects/error.o""\033[m"

