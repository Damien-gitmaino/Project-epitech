/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** tools2
*/

#include "pushswap.h"

void fill_l_a(int ac, char **av, struct tab *tab)
{
    for (int i = 1; i < ac; i++)
        tab->l_a[i - 1] = my_getnbr(av[i]);
}
