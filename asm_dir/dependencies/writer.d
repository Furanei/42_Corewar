objects/writer.o: sources/writer.c asm.h libft/libft.h \
  ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -I./ -Ilibft/ -I./ft_printf/  -c sources/writer.c -o objects/writer.o
	@echo "\033[0;33m""created: objects/writer.o""\033[m"

