/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools3
*/

#include "sokaban.h"

void swap_right_two(struct valeur *init)
{
    init->mesg[init->y_p][init->x_p + 1] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->x_p += 1;
}

void swap_left_two(struct valeur *init)
{
    init->mesg[init->y_p][init->x_p - 1] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->x_p -= 1;
}

void swap_op_two(struct valeur *init)
{
    init->mesg[init->y_p - 1][init->x_p] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->y_p -= 1;
}

void swap_down_two(struct valeur *init)
{
    init->mesg[init->y_p + 1][init->x_p] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->y_p += 1;
}
