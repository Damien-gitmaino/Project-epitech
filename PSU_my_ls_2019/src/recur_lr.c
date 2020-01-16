/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

void open_save_lr(char *tmp)
{
    struct dirent *read;
    struct stat info_f;
    DIR *rep;

    rep = opendir(tmp);
    while ((read = readdir(rep)) != NULL) {
        if ((read->d_name[0] != '.')) {
            stat(tmp, &info_f);
            print_info(info_f);
            my_printf(" %s\n", read->d_name);
        }
    }
    closedir (rep);
}

void print_info_lr(struct dirent *read, char *tmp, char *str)
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

void recur_lr(char *str)
{
    struct dirent *read;
    DIR *rep;
    char *tmp;

    open_save_lr(str);
    rep = opendir(str);
    while ((read = readdir(rep)) != NULL) {
        print_info_lr(read, tmp, str);
    }
    closedir(rep);
}
