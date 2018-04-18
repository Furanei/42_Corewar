../objects/open_files_and_complete_memory_space.o: \
  ../sources/open_files_and_complete_memory_space.c \
  ../includes/open_files_and_complete_memory_space.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/open_files_and_complete_memory_space.c -o ../objects/open_files_and_complete_memory_space.o
	@echo "\033[0;33m""created: ../objects/open_files_and_complete_memory_space.o""\033[m"

