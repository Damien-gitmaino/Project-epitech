##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

SRCS = 	./src/main.c \
		./src/my_ls.c \
		./src/my_read_and_open.c \
		./src/check_intpout.c \
		./src/print_inf.c \
		./src/recur_l.c \
		./src/recur_lr.c

LIBPATH = lib/my/

NAME = my_ls

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -o ${NAME} ${SRCS} -L lib -lmy -I include

clean :
	rm ${NAME}

fclean : clean
	make -C ${LIBPATH} fclean

re : clean fclean all
