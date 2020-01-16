/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools4
*/

#include "sokaban.h"

void op_bis(struct valeur *init)
{
    if (init->mesg[init->y_p - 1][init->x_p] == 'X' &&
        init->mesg[init->y_p - 2][init->x_p] == 'O'
        && init->mesg[init->y_p - 1][init->x_p] != '#')
        swap_op_one(init);
    else if (init->mesg[init->y_p - 1][init->x_p] == 'O')
        swap_op_two(init);
}

void down_bis(struct valeur *init)
{
    if (init->mesg[init->y_p + 1][init->x_p] == 'X'
        && init->mesg[init->y_p + 2][init->x_p] == 'O' &&
        init->mesg[init->y_p + 1][init->x_p] != '#')
        swap_down_one(init);
    else if (init->mesg[init->y_p + 1][init->x_p] == 'O')
        swap_down_two(init);
}

void left_bis(struct valeur *init)
{
    if (init->mesg[init->y_p][init->x_p - 2] == 'O'
        && init->mesg[init->y_p][init->x_p - 1] != '#')
        swap_left_one(init);
    else if (init->mesg[init->y_p][init->x_p - 1] == 'O')
        swap_left_two(init);
}

void right_bis(struct valeur *init)
{
    if (init->mesg[init->y_p][init->x_p + 2] == 'O'
        && init->mesg[init->y_p][init->x_p + 1] != '#')
        swap_right_one(init);
    else if (init->mesg[init->y_p][init->x_p + 1] == 'O')
        swap_right_two(init);
}
