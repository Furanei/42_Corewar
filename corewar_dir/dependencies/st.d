../objects/st.o: ../sources/st.c ../includes/st.h ../includes/mem.h \
  ../includes/op.h ../libft/libft.h ../includes/convert_pc_to_uint.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/st.c -o ../objects/st.o
	@echo "\033[0;33m""created: ../objects/st.o""\033[m"

