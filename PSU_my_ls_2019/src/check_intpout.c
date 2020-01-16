/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

void check_file(char *filepath)
{
    struct stat sb;
    int o = stat(filepath, &sb);

    if (o == -1) {
        my_printf("my_ls: cannot access '%s':", filepath);
        my_printf(" No such file or directory\n");
        exit (84);
    }
    else if (!(S_ISDIR(sb.st_mode))) {
        my_printf("%s\n", filepath);
        exit (0);
    }
}
