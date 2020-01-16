/*
** EPITECH PROJECT, 2020
** fozzbazz
** File description:
** the number is a multiple
*/

#include <stdio.h>
#include <stdlib.h>

int check(char *str, char *tmp)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
            return (1);
    for (int i = 0; tmp[i] != '\0'; i++)
        if (!(tmp[i] >= '0' && tmp[i] <= '9') && str[i] != '-')
            return (1);
    return (0);
}

int l_nb1(int nb1)
{
    if (nb1%2 == 0 && nb1%9 == 0) {
        printf("FozzBazz\n");
        return (0);
    }
    if (nb1%2 == 0)
        printf("Fozz\n");
    else if (nb1%9 == 0)
        printf("Bazz\n");
    else
        printf("%d\n", nb1);
}

int search_mult(int nb1, int nb2)
{
    l_nb1(nb1);
}

int main(int ac, char **av)
{
    int nb1 = 0;
    int nb2 = 0;

    if (ac < 3 || ac > 3)
        return (84);
    if (check(av[1], av[2]) == 1)
        return (84);
    nb1 = atoi(av[1]);
    nb2 = atoi(av[2]);
    if (nb1 > nb2)
        return (84);
    while (nb1 <= nb2) {
        search_mult(nb1, nb2);
        nb1 += 1;
    }
    return (0);
}
