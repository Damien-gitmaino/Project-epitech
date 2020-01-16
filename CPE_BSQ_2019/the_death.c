/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** the_death
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int calc_number(int before, int above, int diagonal, int actualit);

int **located_carre(int **map, char *str, int tmp);

char *recup_number(char *str);

int yop(char *str);

int display_double_tab(int **map, char *str);

int **calc_tab(int **map, char *str)
{
    int k = my_getnbr(recup_number(str)) + 1;
    int number_carat_first_line = yop(str);
    int tmp = 0;

    for (int i = 2; i < k; i++) {
        for (int o = 1; o < number_carat_first_line; o++) {
            map[i][o] = calc_number(map[i][o - 1], \
                map[i - 1][o], map[i - 1][o - 1], map[i][o]);
            if (tmp <= map[i][o])
                tmp = map[i][o];
        }
    }
    map = located_carre(map, str, tmp);
    return (map);
}