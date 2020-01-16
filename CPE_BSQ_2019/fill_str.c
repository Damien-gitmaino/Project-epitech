/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** fill_str
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *recup_number(char *str);

int yop(char *str);

int **located_carre(int **map, char *str);

int **fill_first_ligne(int **map,
        int number_carat_first_line, char *str, int k);

int **calc_tab(int **map, char *str);

int display(int **map, char *str, int tmp, int k)
{
    int number_carat_first_line = yop(str);
    int p = my_strlen(recup_number(str)) + 1;
    int m = p;
    int len = 0;

    for (int i = 1; i < k; i++) {
        for (int o = 0; o < number_carat_first_line; o++) {
            if (map[i][o] == tmp + 1)
                str[p] = 'x';
            p++;
        }
        p++;
    }
    free (map);
    len = my_strlen(str) - m;
    write(1, &str[m], len);
    return (0);
}