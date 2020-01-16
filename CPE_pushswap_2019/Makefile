##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRCS = 	./src/main.c \
		./src/my_pushswap.c \
		./src/tools.c \
		./src/tools_check.c \
		./src/tools2.c

LIBPATH =	lib/my/

NAME = 	push_swap

all : ${NAME}

${NAME} :
		make -C ${LIBPATH} all
		gcc -g -Wall -Wextra -o ${NAME} ${SRCS} -L lib -lmy -I include

clean :
		rm ${NAME}

fclean : clean
		make -C ${LIBPATH} fclean

re : fclean all
