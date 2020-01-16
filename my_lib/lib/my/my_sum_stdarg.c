/*
** EPITECH PROJECT, 2019
** PSU_my_printf_bootstrap_2019
** File description:
** sum_stdarg
*/

#include "my.h"
#include <stdarg.h>

int skip_space(char const *format)
{
    int u = my_strlen(format) - (my_count_number_pourcent(format) * 2);

    return (u);
}

int  sum_stdarg(char const *format, int b, va_list tp)
{
    int res = 0;

    for (int i = 0; i < b; i++)
        res = my_strlen(va_arg(tp, char *)) + res;
    res = skip_space(format) + res;
    return (res);
}
