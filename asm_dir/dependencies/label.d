objects/label.o: sources/label.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/label.c -o objects/label.o
	@echo "\033[0;33m""created: objects/label.o""\033[m"

