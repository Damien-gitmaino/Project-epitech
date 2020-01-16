/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** split
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int number_carat(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

char *recup_number(char *str)
{
    char *new = malloc(sizeof(char) * number_carat(str) + 1);

    new[number_carat(str)] = '\0';
    for (int i = 0; i < number_carat(str); i++)
        new[i] = str[i];
    return (new);
}

int check_colum(char *str, int m)
{
    int tmp = m;

    if (str[m + 1] == '\n' && (str[m] == '.' || str[m] == 'o')) {
        while (str[m] == 'o')
            m = m + 2;
        if (str[m] == '\0') {
            write(1, &str[tmp], my_strlen(str) - tmp);
            return (1);
        }
        str[m] = 'x';
        write(1, &str[tmp], my_strlen(str) - tmp);
        return (1);
    }
    return (0);
}