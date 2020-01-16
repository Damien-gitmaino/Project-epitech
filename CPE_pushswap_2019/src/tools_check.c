/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** tools_check
*/

#include "pushswap.h"

int check_sort(int *list, int nb_carat)
{
    int count = 0;

    for (int i = 0; i < nb_carat - 1; i++) {
        if (list[i] <= list[i + 1])
            count++;
    }
    if (count == nb_carat - 1)
        return (0);
    else
        return (1);
}
