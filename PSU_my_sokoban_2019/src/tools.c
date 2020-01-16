/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** tools
*/

#include "sokaban.h"

int count_number_n(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            res += 1;
    return (res);
}

int my_stat(char const *file)
{
    struct stat *buf = malloc(sizeof(struct stat));
    int size = 0;

    stat(file, buf);
    size = buf->st_size;
    free (buf);
    return (size);
}

int count_number_colum(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

void search_p(struct valeur *init, int nb_ligne, int nb_colum)
{
    init->loop = 1;

    for (int i = 0; i < nb_ligne; i++)
        for (int col = 0; col < nb_colum; col++)
            if (init->mesg[i][col] == 'P') {
                init->x_p = col;
                init->y_p = i;
            }
}

int count_obj(struct valeur *init, int nb_ligne, int nb_colum)
{
    init->nb_obj = 0;

    for (int i = 0; i < nb_ligne; i++)
        for (int col = 0; col < nb_colum; col++)
            if (init->dup[i][col] == 'O' && init->mesg[i][col] == 'X')
                init->nb_obj += 1;
    if (init->nb_obj == init->nb_x)
        return (1);
    return (0);
}
