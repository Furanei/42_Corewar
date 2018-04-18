objects/header.o: sources/header.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/header.c -o objects/header.o
	@echo "\033[0;33m""created: objects/header.o""\033[m"

