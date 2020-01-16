/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** disp_stdarg
*/

#include "my.h"
#include <stdarg.h>

int  disp_stdarg(char *s, ... )
{
    va_list arg;
    va_start(arg, s);

    for (int z = 0; s[z] != '\0'; z++) {
        if (s[z] == 'c')
            my_putchar(va_arg(arg, int));
        if (s[z] == 's')
            my_putstr(va_arg(arg, char *));
        if (s[z] == 'i')
            my_put_nbr(va_arg(arg, int));
        my_putchar('\n');
    }
    va_end(arg);
    return (0);
}