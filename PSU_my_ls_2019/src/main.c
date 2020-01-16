/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '-')
        check_file(av[1]);
    select_mod(ac, av);
    return (0);
}
