/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools2
*/

#include "sokaban.h"

int check_block(int nb_col, struct valeur *init)
{
    int p = 0;

    for (int i = 0; init->mesg[i] != NULL; i++)
        for (int o = 0; o < nb_col; o++)
            if (init->mesg[i][o] == 'X' && ((init->mesg[i - 1][o] == '#' &&
            init->mesg[i][o - 1] == '#')
            || (init->mesg[i - 1][o] == '#' && init->mesg[i][o + 1] == '#')
            || (init->mesg[i + 1][o] == '#' && init->mesg[i][o + 1] == '#')
            || (init->mesg[i + 1][o] == '#' && init->mesg[i][o - 1] == '#')))
                p += 1;
    if (p == init->nb_x)
        return (84);
    return (0);
}

int error_soko(char **map, int nb_ligne, int nb_colum)
{
    int nb = 0;

    for (int i = 0; i < nb_ligne; i++)
        for (int o = 0; o < nb_colum; o++) {
            if (map[i][o] == 'X' || map[i][o] == 'O'
                || map[i][o] == ' ' || map[i][o] == '#'
                || map[i][o] == '\n' || map[i][o] == 'P') {
                nb_ligne = nb_ligne;
            }else{
                return (84);
            }
        }
    for (int i = 0; i < nb_ligne; i++)
        for (int o = 0; o < nb_colum; o++)
            if (map[i][o] == 'P')
                nb++;
    if (nb == 1)
        return (0);
    else
        return (84);
}

void count_x_o(int nb_ligne, int nb_colum, struct valeur *init)
{
    init->nb_x = 0;
    init->nb_o = 0;

    for (int i = 0; i < nb_ligne; i++)
        for (int o = 0; o < nb_colum; o++) {
            if (init->mesg[i][o] == 'O')
                init->nb_o += 1;
            else if (init->mesg[i][o] == 'X')
                init->nb_x += 1;
        }
}

void check_without_o(int nb_ligne, int nb_colum, struct valeur *init)
{
    for (int i = 0; i < nb_ligne; i++)
        for (int o = 0; o < nb_colum; o++) {
            if (init->dup[i][o] == 'O' &&
                init->mesg[i][o] != 'P' && init->mesg[i][o] != 'X')
                init->mesg[i][o] = 'O';
        }
}
