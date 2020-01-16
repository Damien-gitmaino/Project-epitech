/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** my_ls
*/

#include "my_ls.h"

char *check_slash(char *str)
{
    char *new = NULL;
    int u = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '/')
            exit (84);
        else if (str[i + 1] == '\0' && str[i] != '/') {
            new = malloc(sizeof(char) * my_strlen(str) + 2);
            new[my_strlen(str) + 1] = '\0';
            for (; str[u] != '\0'; u++)
                new[u] = str[u];
            new[u] = '/';
            return (new);
        }
    }
    return (str);
}

void select_mod_hard(int ac, char **av)
{
    char *file = NULL;

    if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'l'
        && my_strlen(av[1]) == 2) {
        if (ac == 2)
            open_save(".", "./", ac);
        else {
            file = check_slash(av[2]);
            open_save(file, "./", ac);
        }
    } else if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'R'
        && my_strlen(av[1]) == 2) {
        if (ac == 2) {
            my_printf(".:\n");
            recur_l(".");
        }
    } else
        exit (84);
}

void select_mod(int ac, char **av)
{
    if (ac == 1)
        open_print(0, av[0]);
    else if (ac == 2 && av[1][0] != '-')
        open_print(1, check_slash(av[1]));
    else
        select_mod_hard(ac, av);
}
