/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools_swap
*/

#include "sokaban.h"

void swap_right_one(struct valeur *init)
{
    init->mesg[init->y_p][init->x_p + 2] = 'X';
    init->mesg[init->y_p][init->x_p + 1] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->x_p += 1;
}

void swap_left_one(struct valeur *init)
{
    init->mesg[init->y_p][init->x_p - 2] = 'X';
    init->mesg[init->y_p][init->x_p - 1] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->x_p -= 1;
}

void swap_op_one(struct valeur *init)
{
    init->mesg[init->y_p - 2][init->x_p] = 'X';
    init->mesg[init->y_p - 1][init->x_p] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->y_p -= 1;
}

void swap_down_one(struct valeur *init)
{
    init->mesg[init->y_p + 2][init->x_p] = 'X';
    init->mesg[init->y_p + 1][init->x_p] = 'P';
    init->mesg[init->y_p][init->x_p] = ' ';
    init->y_p += 1;
}
