/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main
*/

#include "pushswap.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        my_printf("\n");
        return (0);
    }
    else if (ac < 2)
        return (84);
    else
        my_pushswap(ac, av);
    return (0);
}
