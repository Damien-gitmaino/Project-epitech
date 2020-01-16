##
## EPITECH PROJECT, 2019
## infinAdd
## File description:
## Makefile
##

SRCS = 		bsq.c\
			split.c\
			main.c\
			check_number_first_ligne.c\
			check_ob_point.c\
			count_number_back_slash_n.c\
			print_number.c\
			calc_number.c \
			tools.c \
			the_death.c \
			located_car.c \
			fill_str.c

LIBPATH = lib/my/

NAME = bsq

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
