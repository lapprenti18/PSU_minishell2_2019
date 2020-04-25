##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME	=	mysh

COMP	=	src/main.c	\
			src/my_strlen.c	\
			src/str_cpy.c	\
			src/prompt.c	\
			src/my_putstr.c	\
			src/siginthandler.c	\
			src/execute_tree.c	\
			src/cat.c	\
			src/no_bin.c	\
			src/str_cmp.c	\
			src/my_str_to_word_array_path.c	\
			src/my_str_to_word_array.c	\
			src/binary.c	\
			src/str_ncmp.c	\
			src/my_memset.c	\
			src/unsetenv.c	\
			src/setenv.c	\
			src/cd.c	\
			src/segfault.c	\
			src/redirect.c	\
			src/test.c

CFLAGS  =	-W -Wall -Wextra -Iinclude -lncurses -g3

all	:
	gcc -o $(NAME) $(COMP) $(CFLAGS)

clean	:
	rm -f *.o

fclean	: clean
	rm -f $(NAME)

re	: fclean all