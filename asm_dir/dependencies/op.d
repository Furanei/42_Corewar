objects/op.o: sources/op.c asm.h libft/libft.h ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/op.c -o objects/op.o
	@echo "\033[0;33m""created: objects/op.o""\033[m"

