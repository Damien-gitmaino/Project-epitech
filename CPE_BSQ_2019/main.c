/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include "my.h"

int fs_print_first_line(char const *filepath);

int main(int ac, char **av)
{
    fs_print_first_line(av[1]);
    return (0);
}
