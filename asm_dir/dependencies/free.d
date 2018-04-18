objects/free.o: sources/free.c asm.h libft/libft.h ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/free.c -o objects/free.o
	@echo "\033[0;33m""created: objects/free.o""\033[m"

