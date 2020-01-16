/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** tools
*/

#include "my.h"

char *recup_number(char *str);

char calc_number(char before, char above, char diagonal, int nb);

int **fill_first_ligne(int **map,
        int number_carat_first_line, char *str, int k)
{
    int p = 0;
    int number = 0;

    for (int i = 0; i < my_strlen(recup_number(str)); i++) {
        map[0][i] = str[p] - 48;
        p++;
    }
    p++;
    for (int i = 1; i < k; i++) {
        for (int o = 0; o < number_carat_first_line; o++) {
            if (str[p] == '.')
                number++;
            map[i][o] = number;
            p++;
            number = 0;
        }
        p++;
    }
    return (map);
}