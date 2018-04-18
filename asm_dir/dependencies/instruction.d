objects/instruction.o: sources/instruction.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/instruction.c -o objects/instruction.o
	@echo "\033[0;33m""created: objects/instruction.o""\033[m"

