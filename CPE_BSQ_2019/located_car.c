/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** located_car
*/

#include "my.h"

int calc_number(int before, int above, int diagonal, int actualit);

char *recup_number(char *str);

int yop(char *str);

int display_double_tab(int **map, char *str);

int display(int **map, char *str, int tmp, int k);

int **print_carat(int **map, int o, int i, int tmp)
{
    int tmp1 = i;

    for (int p = 0; p < tmp; p++) {
        for (int y = 0; y < tmp; y++) {
            map[i][o] = tmp + 1;
            i--;
        }
        i = tmp1;
        o--;
    }
    return (map);
}

int **located_carre(int **map, char *str, int tmp)
{
    int z = 0;
    int k = my_getnbr(recup_number(str)) + 1;
    int number_carat_first_line = yop(str);

    for (int i = 1; i < k; i++)
        for (int o = 0; o < number_carat_first_line; o++)
            if (map[i][o] == tmp) {
                map = print_carat(map, o, i, tmp);
                display(map, str, tmp, k);
                return (0);
            }
    return (0);
}