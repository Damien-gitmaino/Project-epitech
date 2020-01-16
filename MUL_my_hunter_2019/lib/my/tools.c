/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** my_putnbr_base
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int count_str(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    return (i);
}

int check_base(char const *base)
{
    int i = 0;
    int j;

    if (my_strlen(base) < 2)
        return (0);
    while (base[i]) {
        if ((base[i] > 31 && base[i] < 48) || (base[i] > 57 && base[i] < 65) ||
            (base[i] > 90 && base[i] < 97) || base[i] > 123)
            return (0);
        j = i + 1;
        while (base[j]) {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int what_is_base(char *base)
{
    int number_carat = my_strlen(base);

    if (check_base(base) == 0)
        return (0);
    return (number_carat);
}

char *my_getnbr_base(char *base, char carat, int puissance)
{
    int ba = what_is_base(base);
    char *stack = malloc(sizeof(char) * 1 + 1);
    char *result = malloc(sizeof(char) * 32000 + 1);

    stack[1] = '\0';
    stack[0] = carat;
    result = my_supergetnbr(my_getnbr(stack) *
    my_compute_power_rec(ba, puissance));
    return (result);
}

char *new(char *str, char *base)
{
    int i = 0;
    char *tampon = malloc(sizeof(char) * 32000 + 1);
    int puissance = my_strlen(str) - 1;
    char *u = NULL;

    tampon[32000] = '\0';
    for (;str[i] != '\0'; i++, puissance--) {
        tampon = my_supergetnbr(my_getnbr(tampon) +
        my_getnbr(my_getnbr_base(base, str[i], puissance)));
        tampon[count_str(tampon)] = '\0';
    }
    u = malloc(sizeof(char) * my_strlen(tampon) + 1);
    u[my_strlen(tampon)] = '\0';
    i = 0;
    while (i < my_strlen(tampon)) {
        u[i] = tampon[i];
        i++;
    }
    return (u);
}