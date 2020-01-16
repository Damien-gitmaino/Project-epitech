/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** print_number
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *recup_number(char *str);

int **located_carre(int **map, char *str);

int **fill_first_ligne(int **map,
        int number_carat_first_line, char *str, int k);

int **calc_tab(int **map, char *str);

int check_colum(char *str, int m);

int check_one_carat(char *str, int m)
{
    int i = 2;

    if (str[0] == '1' && str[1] == '\n') {
        while (str[i] == 'o' && str[i] != '\0')
            i++;
        if (str[i + 1] == '\0') {
            write(1, &str[m], my_strlen(str) - m);
            return (1);
        }
        str[i] = 'x';
        write(1, &str[m], my_strlen(str) - m);
        return (1);
    }
    return (0);
}

int yop(char *str)
{
    int i = 0;
    int o = 0;

    while (str[i] != '\n')
        i++;
    i++;
    while (str[i] != '\n') {
        i++;
        o++;
    }
    return (o);
}

int display_double_tab(int **map, char *str)
{
    int k = my_getnbr(recup_number(str)) + 1;
    int number_carat_first_line = yop(str);

    for (int i = 1; i < k; i++) {
        for (int o = 0; o < number_carat_first_line; o++)
            my_put_nbr(map[i][o]);
        my_putchar('\n');
    }
}

int **fill(char *str, int m)
{
    int number_carat_first_line = yop(str);
    int k = my_getnbr(recup_number(str)) + 1;
    int **map = malloc(sizeof(int *) * k + 1);
    int p = 0;

    if (check_one_carat(str, m) == 1)
        return (0);
    map[0] = malloc(sizeof(int) * m + 2);
    map[m + 1] = '\0';
    for (int u = 1; u < k; u++) {
        map[u] = malloc(sizeof(int) * number_carat_first_line + 1);
    }
    fill_first_ligne(map, number_carat_first_line, str, k);
    return (map);
}

char *print_number(char *str, int i)
{
    int number = 0;
    int k = my_getnbr(recup_number(str)) + 1;
    int **map = NULL;
    int m = my_strlen(recup_number(str));

    if (check_one_carat(str, m + 1) == 1)
        return (0);
    if (check_colum(str, m + 1) == 1)
        return (0);
    map = fill(str, m);
    map = calc_tab(map, str);
    return (0);
}
