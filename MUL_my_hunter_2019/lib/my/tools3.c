/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** tools3
*/

#include "my.h"
#include <stdlib.h>

int i_like_cs(char const *format, int d)
{
    my_putchar('%');
    d = d + 2;
    while (format[d] == ' ') {
        my_putchar(' ');
        d++;
    }
    my_putchar(format[d]);
    d++;
    return (d);
}

int print_printf(char const *format, void (*pointeur[10])(va_list),
                int d, va_list arg)
{
    int locate = 0;

    for (int p = 0; my_count_number_pourcent(format) != p; p++) {
        d = print_carat(format, d);
        if (format[d] == '%' && format[d + 1] == '%') {
            d = i_like_cs(format, d);
        } else {
            locate = flags(format, d);
            if (locate == 84)
                return (84);
            pointeur[locate](arg);
            d = d + 2;
        }
    }
    d = print_carat(format, d);
    return (d);
}