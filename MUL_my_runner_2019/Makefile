##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## Makefile
##

SRCS =	./src/main.c \
		./src/initialisation.c \
		./src/display_sprite.c \
		./src/tools_clock.c \
		./src/tools_clock_bis.c \
		./src/read_map.c \
		./src/what_is_obs.c \
		./src/disp_obs.c \
		./src/game_over.c \
		./src/pause.c \
		./src/win.c \
		./src/sound.c

LIBPATH = lib/my/

NAME = my_runner

all : ${NAME}

${NAME} :
	make -C ${LIBPATH} all
	gcc -g -o ${NAME} ${SRCS} -L lib -lmy -I include -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean :
	make -C ${LIBPATH} clean

fclean :
	make -C ${LIBPATH} fclean
	rm -f $(NAME)

re : fclean all
