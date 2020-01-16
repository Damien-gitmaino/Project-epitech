##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

HEADER = my.h

HEADPATH = ../../include/

SRCS =  my_compute_power_rec.c my_compute_square_root.c my_find_prime_sup.c my_getnbr.c my_isneg.c my_is_prime.c my_putchar.c my_put_nbr.c my_putstr.c my_revstr.c my_showmen.c my_showstr.c my_sort_int_array.c my_strcat.c my_strcmp.c my_strcpy.c my_str_isalpha.c my_str_islower.c my_str_isnum.c my_str_isprintable.c my_str_isupper.c my_strlen.c my_strlowcase.c my_strncat.c my_strncmp.c my_strncpy.c my_strstr.c my_strupcase.c my_swap.c my_sum_stdarg.c my_printf.c my_count_number_pourcent.c tools_my_printf.c tools_my_printf2.c my_put_binary.c my_put_hexa.c my_put_octal.c my_put_unsigned_int.c my_supergetnbr.c my_put_unsigned_str.c my_put_hexa_capitalize.c my_put_str_for_s.c my_put_pointeur.c tools3.c

OBJ = ${SRCS:.c=.o}

NAME = libmy.a

LIBPATH = ../

all : ${NAME}

${NAME} :
	gcc -c ${SRCS}
	ar rc ${NAME} ${OBJ}
	cp ${HEADER} ${HEADPATH}
	cp ${NAME} ${LIBPATH}

clean :
	rm ${OBJ}
	rm ${NAME}

fclean : clean
	rm ${HEADPATH}${HEADER}
	rm ${LIBPATH}${NAME}

re : fclean all