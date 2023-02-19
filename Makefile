##
## EPITECH PROJECT, 2023
## B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
## File description:
## Makefile
##

SRC =	main.c					\
		bsq.c					\
		lib.c					\
		init.c

OBJ =	$(SRC:.c=.o)

NAME =	bsq

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC)
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
