/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** sum_stdarg
*/

#include "my.h"
#include <stdarg.h>

int  sum_stdarg(int nb , ... )
{
    va_list arg;
    va_start(arg, nb);
    int z = 0;

    for (;nb > 0; nb--)
        z = my_strlen(va_arg(arg, char *)) + z;
    va_end(arg);
    return (z);
}
