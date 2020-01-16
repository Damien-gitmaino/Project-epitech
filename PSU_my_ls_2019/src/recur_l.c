/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

void open_print_two(char *str)
{
    struct dirent *read;
    DIR *rep;

    rep = opendir(str);
    while ((read = readdir(rep)) != NULL)
        if (read->d_name[0] != '.')
            my_printf("%s\n", read->d_name);
    closedir(rep);
}

char *cod_i_str(char *dest, char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(dest) + my_strlen(str) + 1);
    int run = 0;

    new[my_strlen(dest) + my_strlen(str)] = '\0';
    for (int i = 0; dest[i] != '\0'; i++, run++)
        new[run] = dest[i];
    for (int i = 0; str[i] != '\0'; i++, run++)
        new[run] = str[i];
    return (new);
}

void print_info_r(struct dirent *read, char *tmp, char *str)
{
    struct stat info_t;

    if ((read->d_name[0] != '.')) {
        tmp = cod_i_str(cod_i_str(str, "/"), read->d_name);
        stat(tmp, &info_t);
        if (S_ISDIR(info_t.st_mode) && read->d_name[0] != '.') {
            my_putchar('\n');
            my_printf("%s:\n", tmp);
            recur_l(tmp);
        }
    }
}

void recur_l(char *str)
{
    struct dirent *read;
    DIR *rep;
    char *tmp;

    open_print_two(str);
    rep = opendir(str);
    while ((read = readdir(rep)) != NULL) {
        print_info_r(read, tmp, str);
    }
    closedir(rep);
}
