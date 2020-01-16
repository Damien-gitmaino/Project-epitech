##
## EPITECH PROJECT, 2019
## mettre le nom du projet ..........................................................................
## File description:
## Makefile
##

SRCS = 	#mettre vos file

LIBPATH = lib/my/

NAME = #mettre votre nom de binayre

all : ${NAME}

CFLAGS += -W -Wall -Wextra

${NAME} :
	make -C ${LIBPATH} all
	gcc -o ${NAME} ${SRCS} -L lib -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : clean fclean all
