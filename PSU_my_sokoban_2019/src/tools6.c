/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_tools
*/

#include "sokaban.h"
#include "my.h"

void moove_op(struct valeur *init)
{
    if (init->mesg[init->y_p - 1][init->x_p] == ' ' &&
        init->mesg[init->y_p - 1][init->x_p] != '#') {
        my_swap(&init->mesg[init->y_p - 1][init->x_p],
                &init->mesg[init->y_p][init->x_p]);
        init->y_p -= 1;
    }
    else if (init->mesg[init->y_p - 1][init->x_p] == 'X' &&
                init->mesg[init->y_p - 2][init->x_p] != '#'
                && init->mesg[init->y_p - 2][init->x_p] != 'O'
                && init->mesg[init->y_p - 2][init->x_p] != 'X') {
        my_swap(&init->mesg[init->y_p - 1][init->x_p],
                &init->mesg[init->y_p - 2][init->x_p]);
        my_swap(&init->mesg[init->y_p - 1][init->x_p],
                &init->mesg[init->y_p][init->x_p]);
        init->y_p -= 1;
    } else
        op_bis(init);
}

void moove_down(struct valeur *init)
{
    if (init->mesg[init->y_p + 1][init->x_p] == ' ' &&
        init->mesg[init->y_p + 1][init->x_p] != '#') {
        my_swap(&init->mesg[init->y_p + 1][init->x_p],
                &init->mesg[init->y_p][init->x_p]);
        init->y_p += 1;
    }
    else if (init->mesg[init->y_p + 1][init->x_p] == 'X' &&
                init->mesg[init->y_p + 2][init->x_p] != '#'
                && init->mesg[init->y_p + 2][init->x_p] != 'O'
            && init->mesg[init->y_p + 2][init->x_p] != 'X') {
        my_swap(&init->mesg[init->y_p + 1][init->x_p],
                &init->mesg[init->y_p + 2][init->x_p]);
        my_swap(&init->mesg[init->y_p + 1][init->x_p],
                &init->mesg[init->y_p][init->x_p]);
        init->y_p += 1;
    } else
        down_bis(init);
}

void moove_left(struct valeur *init)
{
    if (init->mesg[init->y_p][init->x_p - 1] == ' ' &&
        init->mesg[init->y_p][init->x_p - 1] != '#') {
        my_swap(&init->mesg[init->y_p][init->x_p - 1],
                &init->mesg[init->y_p][init->x_p]);
        init->x_p -= 1;
    }
    else if (init->mesg[init->y_p][init->x_p - 1] == 'X' &&
            init->mesg[init->y_p][init->x_p - 2] != '#'
            && init->mesg[init->y_p][init->x_p - 2] != 'O'
            && init->mesg[init->y_p][init->x_p - 2] != 'X'
            && init->x_p > 1) {
        my_swap(&init->mesg[init->y_p][init->x_p - 1],
                &init->mesg[init->y_p][init->x_p - 2]);
        my_swap(&init->mesg[init->y_p][init->x_p - 1],
                &init->mesg[init->y_p][init->x_p]);
        init->x_p -= 1;
    } else
        left_bis(init);
}

void moove_right(struct valeur *init)
{
    if (init->mesg[init->y_p][init->x_p + 1] == ' ' &&
        init->mesg[init->y_p][init->x_p + 1] != '#') {
        my_swap(&init->mesg[init->y_p][init->x_p + 1],
                &init->mesg[init->y_p][init->x_p]);
        init->x_p += 1;
    }
    else if (init->mesg[init->y_p][init->x_p + 1] == 'X' &&
            init->mesg[init->y_p][init->x_p + 2] != '#'
            && init->mesg[init->y_p][init->x_p + 2] != 'O'
            && init->mesg[init->y_p][init->x_p + 2] != 'X'
            && init->x_p < init->nub_col - 2) {
        my_swap(&init->mesg[init->y_p][init->x_p + 1],
                &init->mesg[init->y_p][init->x_p + 2]);
        my_swap(&init->mesg[init->y_p][init->x_p + 1],
                &init->mesg[init->y_p][init->x_p]);
        init->x_p += 1;
    } else
        right_bis(init);
}
