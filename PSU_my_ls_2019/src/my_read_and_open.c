/*
** EPITECH PROJECT, 2020
** my_ls_tmp
** File description:
** main
*/

#include "my_ls.h"

char *cod_i_reaload(int run, char *str, char *tmp, char *file)
{
    int nb_carat = my_strlen(str) + my_strlen(tmp) + my_strlen(file);
    char *new = malloc(sizeof(char) * nb_carat + 1);

    new[nb_carat] = '\0';
    new[0] = '.';
    new[1] = '/';
    for (int i = 0; i < my_strlen(file); i++, run++)
        new[run] = file[i];
    for (int i = 0; i < my_strlen(str); i++, run++)
        new[run] = str[i];
    return (new);
}

char *filepath_reload(char *str, char *tmp, int ac, char *file)
{
    int nb_carat = my_strlen(str) + my_strlen(tmp);
    char *new = NULL;
    int run = 2;

    if (ac == 2) {
        new = malloc(sizeof(char) * nb_carat + 1);
        new[nb_carat] = '\0';
        new[0] = '.';
        new[1] = '/';
        for (int i = 0; i < nb_carat; i++, run++)
            new[run] = str[i];
        return (new);
    } else
        return (cod_i_reaload(run, str, tmp, file));
}

void print_droit(struct stat *info_f)
{
    (S_ISDIR(info_f->st_mode)) ? my_printf("d") : my_printf("-");
    (info_f->st_mode & S_IRUSR) ? my_printf("r") : my_printf("-");
    (info_f->st_mode & S_IWUSR) ? my_printf("w") : my_printf("-");
    (info_f->st_mode & S_IXUSR) ? my_printf("x") : my_printf("-");
    (info_f->st_mode & S_IRGRP) ? my_printf("r") : my_printf("-");
    (info_f->st_mode & S_IWGRP) ? my_printf("w") : my_printf("-");
    cod_i_print_ex(info_f);
    (info_f->st_mode & S_IROTH) ? my_printf("r") : my_printf("-");
    (info_f->st_mode & S_IWOTH) ? my_printf("w") : my_printf("-");
    cod_i_print_ex_t(info_f);
}

void open_save(char *str, char *tmp, int ac)
{
    struct dirent *read;
    struct stat info_f;
    DIR *rep;

    rep = opendir(str);
    while ((read = readdir(rep)) != NULL) {
        if ((read->d_name[0] != '.')) {
            tmp = filepath_reload(read->d_name, tmp, ac, str);
            stat(tmp, &info_f);
            print_info(info_f);
            my_printf(" %s\n", read->d_name);
        }
    }
    closedir (rep);
}

void open_print(int nb, char *folder)
{
    struct dirent *read;
    DIR *rep;

    if (nb == 1)
        rep = opendir(folder);
    else
        rep = opendir(".");
    while ((read = readdir(rep)) != NULL)
        if (read->d_name[0] != '.')
            my_printf("%s\n", read->d_name);
    closedir(rep);
}
