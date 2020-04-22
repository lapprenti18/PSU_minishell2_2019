##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	main.c	\
		cat.c	\
		my_putstr.c	\
		my_strlen.c	\
		no_bin.c	\
		str_cmp.c	\
		my_str_to_word_array_path.c	\
		my_str_to_word_array.c	\
		binary.c	\
		prompt.c	\
		str_ncmp.c	\
		str_cpy.c	\
		my_memset.c	\
		unsetenv.c	\
		setenv.c	\
		cd.c	\
		segfault.c	\

NAME	=	mysh

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	gcc -o $(NAME) $(SRC) $(ERROR) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
