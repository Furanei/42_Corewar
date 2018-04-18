objects/extract.o: sources/extract.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/extract.c -o objects/extract.o
	@echo "\033[0;33m""created: objects/extract.o""\033[m"

