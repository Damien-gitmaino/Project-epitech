/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

void print_info(struct stat info_f)
{
    struct passwd *passwd;
    struct group *grp;

    passwd = getpwuid(info_f.st_uid);
    grp = getgrgid(info_f.st_gid);
    print_droit(&info_f);
    my_printf(" %d %s ", info_f.st_nlink, passwd->pw_name);
    my_printf("%s %d ", grp->gr_name, info_f.st_size);
    write(1, ctime(&info_f.st_mtime), \
    my_strlen(ctime(&info_f.st_mtime)) - 9);
}

void cod_i_print_ex(struct stat *info_f)
{
    if ((info_f->st_mode & S_ISGID) && !(info_f->st_mode & S_IXGRP))
        my_putchar('S');
    else if ((info_f->st_mode & S_ISGID) && (info_f->st_mode & S_IXGRP))
        my_putchar('s');
    else
        (info_f->st_mode & S_IXGRP) ? my_printf("x") : my_printf("-");
}

void cod_i_print_ex_t(struct stat *info_f)
{
    if ((info_f->st_mode & S_ISVTX) && !(info_f->st_mode & S_IXOTH))
        my_putchar('T');
    else if ((info_f->st_mode & S_ISVTX) && (info_f->st_mode & S_IXOTH))
        my_putchar('t');
    else
        (info_f->st_mode & S_IXOTH) ? my_printf("x") : my_printf("-");
}
