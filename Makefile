##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	navy.c \
		map.c \
		signal.c \
		my_itoa.c \
		create_map2.c \
		attack.c \
		signal2.c \

OBJS = $(SRCS:.c=.o)

NAME = navy

all : $(NAME)

$(NAME) :
		make -C lib/my
		gcc -g -o $(NAME) $(SRCS) -L lib/ -lmy -I /include/
		make clean -C lib/my

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all