##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

SRC 	=	my_hunter.c \
			display.c \
			manage_mouse.c \
			tire_h.c \
			menu.c \
			mouvemt.c \
			draw_sprite_coopa.c \
			tools_text.c \
			my_supergetnbr.c

LIBPATH = lib/my/

NAME 	= 	my_hunter

all:	$(NAME)

$(NAME):
	make -C ${LIBPATH} all
	gcc -g -o ${NAME} ${SRC} -L lib -lmy -I include -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean:
		make -C ${LIBPATH} clean
		rm -f $(OBJ)

fclean:
		make -C ${LIBPATH} fclean
		rm -f $(NAME)

re: 	fclean all
