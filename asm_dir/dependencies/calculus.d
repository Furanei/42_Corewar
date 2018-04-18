objects/calculus.o: sources/calculus.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/calculus.c -o objects/calculus.o
	@echo "\033[0;33m""created: objects/calculus.o""\033[m"

