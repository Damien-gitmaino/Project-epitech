/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** gameplay
*/

#include "sokaban.h"

void print_map(struct valeur *init, int number_n, char *tmp)
{
    getmaxyx(stdscr, init->row, init->col);
    init->row = (init->row - (number_n / 2) * 2) / 2;
    for (int i = 0; i < number_n; i++) {
        mvprintw(init->row, (init->col - my_strlen(init->mesg[i])) / 2,
                "%s\n", init->mesg[i]);
        init->row += 1;
    }
}

void bis(int number_n, char *tmp,
        struct valeur *init)
{
    print_map(init, number_n, tmp);
    refresh();
}

void super_game(int number_n, char *tmp,
        struct valeur *init)
{
    void (*pointeur[4]) (struct valeur *) =
                                    {moove_right, moove_left, moove_op, \
                                    moove_down};
    int press[5] = {KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, 0};

    while (1) {
        keypad(stdscr, TRUE);
        for (int i = 0; press[i] != 0; i++)
            if (init->key == press[i])
                pointeur[i](init);
        check_without_o(number_n, count_number_colum(tmp), init);
        print_map(init, number_n, tmp);
        if (count_obj(init, number_n, count_number_colum(tmp)) == 1
            || check_block(count_number_colum(tmp), init) == 84)
            break;
        init->key = getch();
        refresh();
    }
    bis(number_n, tmp, init);
}

int game(int number_n, char *tmp,
        struct valeur *init)
{
    initscr();
    noecho();
    search_p(init, number_n, count_number_colum(tmp));
    count_x_o(number_n, count_number_colum(tmp), init);
    if (init->nb_o > init->nb_x) {
        endwin();
        return (84);
    }
    if (error_soko(init->mesg, number_n, count_number_colum(tmp)) == 84) {
        endwin();
        return (84);
    }
    super_game(number_n, tmp, init);
    endwin();
    return (0);
}
