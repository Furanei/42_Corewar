../objects/main.o: ../sources/main.c ../includes/main.h ../libft/libft.h \
  ../includes/mem.h ../includes/op.h ../includes/help_corewar.h \
  ../includes/set_op_tab.h ../includes/live.h \
  ../includes/convert_pc_to_uint.h ../includes/ld.h ../includes/st.h \
  ../includes/add.h ../includes/sub.h ../includes/and.h ../includes/or.h \
  ../includes/xor.h ../includes/zjmp.h ../includes/ldi.h \
  ../includes/sti.h ../includes/fork_e.h ../includes/lld.h \
  ../includes/lldi.h ../includes/lfork_e.h ../includes/aff.h \
  ../includes/set_options.h ../includes/set_champ.h \
  ../includes/set_process.h \
  ../includes/open_files_and_complete_memory_space.h \
  ../includes/cycle_plus_plus.h ../includes/change_op.h \
  ../includes/do_op.h ../includes/test_argument_coding_bytes.h \
  ../includes/dump.h ../includes/secure_define.h
	@gcc -Wall -Wextra -Werror -I../includes/ -I../libft/  -c ../sources/main.c -o ../objects/main.o
	@echo "\033[0;33m""created: ../objects/main.o""\033[m"

