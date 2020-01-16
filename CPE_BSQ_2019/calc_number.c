/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** calc_number
*/

#include "my.h"

int sort(int before, int above, int diagonal)
{
    if (before >= above && above <= diagonal)
        return (above + 1);
    else if (before <= above && before <= diagonal)
        return (before + 1);
    else
        return (diagonal + 1);
}

int calc_number(int before, int above, int diagonal, int actualit)
{
    int number = 0;

    if (actualit == 0)
        return (0);
    return (sort(before, above, diagonal));
}
