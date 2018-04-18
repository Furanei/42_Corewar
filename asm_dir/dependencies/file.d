objects/file.o: sources/file.c asm.h libft/libft.h ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/file.c -o objects/file.o
	@echo "\033[0;33m""created: objects/file.o""\033[m"

