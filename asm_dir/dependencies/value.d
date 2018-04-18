objects/value.o: sources/value.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/value.c -o objects/value.o
	@echo "\033[0;33m""created: objects/value.o""\033[m"

