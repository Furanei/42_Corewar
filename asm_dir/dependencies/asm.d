objects/asm.o: sources/asm.c asm.h libft/libft.h ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/asm.c -o objects/asm.o
	@echo "\033[0;33m""created: objects/asm.o""\033[m"

