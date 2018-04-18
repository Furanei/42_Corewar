../objects/set_op_tab.o: ../sources/set_op_tab.c ../includes/set_op_tab.h \
  ../includes/mem.h ../includes/op.h ../libft/libft.h ../includes/live.h \
  ../includes/convert_pc_to_uint.h ../includes/ld.h ../includes/st.h \
  ../includes/add.h ../includes/sub.h ../includes/and.h ../includes/or.h \
  ../includes/xor.h ../includes/zjmp.h ../includes/ldi.h \
  ../includes/sti.h ../includes/fork_e.h ../includes/lld.h \
  ../includes/lldi.h ../includes/lfork_e.h ../includes/aff.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/set_op_tab.c -o ../objects/set_op_tab.o
	@echo "\033[0;33m""created: ../objects/set_op_tab.o""\033[m"

