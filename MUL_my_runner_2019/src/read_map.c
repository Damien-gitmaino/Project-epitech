/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** read_map
*/

#include "runner.h"
#include <fcntl.h>
#include <unistd.h>

int count_number_n(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            res += 1;
    return (res);
}

int count_number_colum(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

char **fill(char *str)
{
    int nb_ligne = count_number_n(str);
    int nb_colum = count_number_colum(str);
    int index_str = 0;
    char **map = malloc(sizeof(char *) * nb_ligne + 1);

    for (int i = 0; i < nb_ligne; i++) {
        map[i] = malloc(sizeof(char) * nb_colum + 1);
        map[i][nb_colum] = '\0';
    }
    for (int i = 0; i < nb_ligne; i++) {
        for (int o = 0; str[index_str] != '\n'; o++) {
            map[i][o] = str[index_str];
            index_str += 1;
        }
        index_str += 1;
    }
    return (map);
}

void fs_print_first_line(char const *filepath, struct tab *tab)
{
    int fd = open(filepath, O_RDONLY);
    int size;
    char *buffer;
    int read_c;

    size = 320000;
    buffer = malloc(sizeof(char) * size + 1);
    read_c = read(fd, buffer, size);
    buffer[size] = '\0';
    tab->obs.x_map = count_number_colum(buffer);
    tab->obs.y_map = count_number_n(buffer);
    tab->obs.map = fill(buffer);
    close (fd);
}
