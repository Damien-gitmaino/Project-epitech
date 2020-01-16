/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** check_number_first_ligne
*/

#include "my.h"

char *recup_number(char *str);

int check_number_first_ligne(char *str)
{
    int y = my_strlen(recup_number(str));

    for (int i = 0; str[i] != '\n' && str[i] >= '0' && str[i] <= '9'; i++)
    if (y == i)
        return (0);
    else
        return (84);

}