##
## Makefile for lem_in in /home/schmou_a/Progelem/CPE_2014_lemin
##
## Made by schmou_a
## Login   <schmou_a@epitech.net>
##
## Started on  Wed Apr 22 11:02:46 2015 schmou_a
## Last update Sun May  3 21:43:28 2015 guigui
##

LIB		= libmy.a

AR_RC		= ar rc

NAME		= lem_in

RANLIB		= ranlib

LIB_SRCS	= lib_src/convert_base.c \
		  lib_src/get_next_line.c \
		  lib_src/tab_len.c \
		  lib_src/get_option.c \
		  lib_src/is_option.c \
		  lib_src/listes.c \
		  lib_src/listes2.c \
		  lib_src/my_atoi.c \
		  lib_src/my_countnb_b.c \
		  lib_src/my_epur_str.c \
		  lib_src/my_find_prime_sup.c \
		  lib_src/my_get_el.c \
		  lib_src/my_getnbr.c \
		  lib_src/my_getnbr_base.c \
		  lib_src/my_isneg.c \
		  lib_src/my_is_prime.c \
		  lib_src/my_malloc.c \
		  lib_src/my_malloc2.c \
		  lib_src/my_parse.c \
		  lib_src/my_power_it.c \
		  lib_src/my_power_rec.c \
		  lib_src/my_printf.c \
		  lib_src/my_put.c \
		  lib_src/my_putblank.c \
		  lib_src/my_putchar.c \
		  lib_src/my_putchar2.c \
		  lib_src/my_putint.c \
		  lib_src/my_put_nbr.c \
		  lib_src/my_putnbr_base.c \
		  lib_src/my_putnbr_base2.c \
		  lib_src/my_putptr.c \
		  lib_src/my_putstr.c \
		  lib_src/my_putstr2.c \
		  lib_src/my_revstr.c \
		  lib_src/my_round.c \
		  lib_src/my_showmem.c \
		  lib_src/my_showstr.c \
		  lib_src/my_show_wordtab.c \
		  lib_src/my_sort_int_tab.c \
		  lib_src/my_square_root.c \
		  lib_src/my_strcapitalize.c \
		  lib_src/my_strcat.c \
		  lib_src/my_strcmp.c \
		  lib_src/my_strcpy.c \
		  lib_src/my_strdup.c \
		  lib_src/my_str_isalpha.c \
		  lib_src/my_str_islower.c \
		  lib_src/my_str_isnum.c \
		  lib_src/my_str_isprintable.c \
		  lib_src/my_str_isupper.c \
		  lib_src/my_strlcat.c \
		  lib_src/my_strlen.c \
		  lib_src/my_strlowcase.c \
		  lib_src/my_strnbr.c \
		  lib_src/my_strncat.c \
		  lib_src/my_strncmp.c \
		  lib_src/my_strncpy.c \
		  lib_src/my_strstr.c \
		  lib_src/my_strtab.c \
		  lib_src/my_strtok.c \
		  lib_src/my_str_to_wordtab.c \
		  lib_src/my_strupcase.c \
		  lib_src/my_swap.c \
		  lib_src/my_uppercase.c \
		  lib_src/worknb.c \
		  lib_src/file/get_ram.c \
		  lib_src/file/my_fdup.c \
		  lib_src/file/my_fgeti.c \
		  lib_src/file/my_fgetsize.c \
		  lib_src/file/my_fread.c \
		  lib_src/file/my_opcl.c \
		  lib_src/file/my_fwrite.c \
		  lib_src/print_binary.c \
		  lib_src/flip_endian.c \
		  lib_src/tab_len.c \
		  lib_src/gnl_querat_g.c \
		  lib_src/gen_flip_endian.c \
		  lib_src/hashtable.c \
		  lib_src/hashtable2.c \
		  lib_src/hashtable3.c \
		  lib_src/my_memcpy.c \
		  lib_src/my_ptrcmp.c \
		  lib_src/my_ptrdup.c \
		  lib_src/my_strndup.c

SRCS		= src/main.c \
                  src/edges.c \
		  src/edges2.c \
		  src/add_node.c \
		  src/init_network.c \
		  src/brk_node.c \
		  src/find_node.c \
		  src/free_network.c \
		  src/print_network.c \
		  src/slist_create.c \
		  src/slist_destroy.c \
		  src/slist_util.c \
		  src/do_parser.c \
		  src/my_perror.c \
		  src/do_output.c \
		  src/parse_stdin.c \
		  src/build_tree.c \
	 	  src/search_tree.c \
		  src/build_lemintree.c \
		  src/lemin_startend.c \
		  src/show_tree.c \
		  src/lid_methods1.c \
		  src/lid_methods2.c \
		  src/create_room.c \
	 	  src/leminpipes.c \
		  src/do_ant.c

LIB_OBJS	= $(LIB_SRCS:.c=.o)

OBJS		= $(SRCS:.c=.o)

SAVS_HDS	= include/file.h~ \
		  include/format.h~ \
		  include/hashtable.h~ \
		  include/listes.h~ \
		  include/my.h~ \
		  include/my_mem.h~ \
		  include/my_printf.h~ \
		  include/str_to_wordtab.h~

SAVS_LIB	= $(LIB_SRCS:.c=.c~)

SAVS_PRJ	= $(SRCS:.c=.c~)

RM		= rm -f

CC		= gcc

CFLAGS		= -Wall -Wextra -I./include

LDFLAGS		= -lmy -L.

all:		$(LIB) $(NAME)

$(LIB):		$(LIB_OBJS)
		$(AR_RC) $(LIB) $(LIB_OBJS)
		$(RANLIB) $(LIB)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

test:
	./tests/testLemIn.sh

clean:
		$(RM) $(LIB_OBJS)
		$(RM) $(OBJS)
		$(RM) $(SAVS_LIB)
		$(RM) $(SAVS_PRJ)
		$(RM) Makefile~

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(ASM)
		$(RM) $(LIB)
		$(RM) $(DSM)

re:		fclean all

.PHONY: all clean fclean re test
