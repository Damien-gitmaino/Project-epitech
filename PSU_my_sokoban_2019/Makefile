##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## Makefile
##

SRCS = 	./src/sokaban.c \
		./src/tools.c \
		./src/tools6.c \
		./src/gameplay.c \
		./src/tools2.c \
		./src/tools5.c \
		./src/tools3.c \
		./src/tools4.c \
		./src/tireh.c

LIBPATH = lib/my/

NAME = my_sokoban

FLAGS += -Wall -Wextra

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -lncurses -o ${NAME} ${SRCS} -L lib -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : fclean all
