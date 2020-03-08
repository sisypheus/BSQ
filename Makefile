##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile
##

SRC	=	set_copy.c	\
		replace.c	\
		print_res.c	\
		calcul_algo.c

LSRC	=	lib/my/my_getnbr.c		\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putstr.c		\
			lib/my/my_revstr.c		\
			lib/my/my_strcpy.c		\
			lib/my/my_strdup.c		\
			lib/my/my_strlen.c		\
			lib/my/my_str_to_int.c

LOBJ	=	$(LSRC:.c=.o)

NAME	=	bsq

LIB_PATH =  ./lib/my

INCLUDE_PATH	=	./include

all:	$(NAME)

$(NAME):	$(LOBJ)
	ar rc lib/my/libmy.a $(LOBJ)
	cp lib/my/my.h ./include/
	cp lib/my/bsq.h ./include/
	gcc $(SRC) -o $(NAME) -L$(LIB_PATH) -lmy -I ./include -g

clean:
	rm -rf $(NAME)
	rm -rf $(LOBJ)

fclean:		clean
	rm -rf $(NAME)
	rm -rf *.o

re: fclean all
