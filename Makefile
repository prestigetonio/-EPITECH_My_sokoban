##
## EPITECH PROJECT, 2023
## makefile
## File description:
## emacs
##

NAME = my_sokoban

SRC =   src/my_sokoban.c	\
		src/my_sokoban2.c	\
		lib/my/my_strlen.c  \
		lib/my/my_strlen_soko.c  \
		lib/my/my_strdup.c  \
		lib/my/my_put_nbr.c  \
		lib/my/my_strcpy.c  \
		lib/my/my_put_nbru.c  \
		lib/my/my_printf.c  \
		lib/my/my_putchar.c  \
		lib/my/my_putstr.c  \
		main.c              \

OBJ =  $(SRC:.c=.o)

CFLAGS = -I ./include -Wall

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

all : $(NAME)

debug :
	gcc -o $(NAME) $(SRC) -lncurses -g3

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#

fclean : clean
	rm -f $(NAME)

re : fclean all
